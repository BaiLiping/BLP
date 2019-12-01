import numpy as np
import matplotlib.pyplot as plt
import gym
import sys
from env import PhasedArrayEnv
import torch
from torch import nn
from torch import optim

env = PhasedArrayEnv()
class policy_estimator():
    def __init__(self, env):
        self.n_inputs = env.get_nS()
        self.n_outputs = env.get_nA()

        # Define network
        self.network = nn.Sequential(
            nn.Linear(self.n_inputs, 512),
            nn.ReLU(),
            nn.Linear(512,128),
            nn.ReLU(),
            nn.Linear(128,64),
            nn.ReLU(),
            nn.Linear(64,16),
            nn.ReLU(),
            nn.Linear(16, self.n_outputs),
            nn.Softmax(dim=-1))

    def predict(self, state):
        action_probs = self.network(torch.FloatTensor(state))
        return action_probs
pe=policy_estimator(env)
def discount_rewards(rewards, gamma=0.99):
    r = np.array([gamma**i * rewards[i]
                  for i in range(len(rewards))])
    # Reverse the array direction for cumsum and then
    # revert back to the original order
    r = r[::-1].cumsum()[::-1]
    return r - r.mean()

def reinforce(env, policy_estimator, num_episodes=20000,
              batch_size=10, gamma=0.99):

    # Set up lists to hold results
    total_rewards = []
    batch_rewards = []
    batch_actions = []
    batch_states = []
    batch_counter = 1
    
    # Define optimizer
    optimizer = optim.Adam(policy_estimator.network.parameters(), 
                           lr=0.01)
    
    action_space = np.arange(env.get_nA())
    for ep in range(num_episodes):
        s_0 = env.reset()
        states = []
        rewards = []
        actions = []
        for i in range(48):
            # Get actions and convert to numpy array
            action_probs = policy_estimator.predict(s_0).detach().numpy()
            action = np.random.choice(action_space, p=action_probs)
            s_1, r = env.step(action)
            
            states.append(s_0)
            rewards.append(r)
            actions.append(action)
            s_0 = s_1
            
        # If complete, batch data
        batch_rewards.extend(discount_rewards(rewards, gamma))
        batch_states.extend(states)
        batch_actions.extend(actions)
        batch_counter += 1
        total_rewards.append(sum(rewards))
        
        # If batch is complete, update network
        if batch_counter == batch_size:
            optimizer.zero_grad()
            state_tensor = torch.FloatTensor(batch_states)
            reward_tensor = torch.FloatTensor(batch_rewards)
            # Actions are used as indices, must be LongTensor
            action_tensor = torch.LongTensor(batch_actions)
            
            # Calculate loss
            logprob = torch.log(
                policy_estimator.predict(state_tensor))
            selected_logprobs = reward_tensor * \
                logprob[np.arange(len(action_tensor)), action_tensor]
            loss = -selected_logprobs.mean()
            
            # Calculate gradients
            loss.backward()
            # Apply gradients
            optimizer.step()
            
            batch_rewards = []
            batch_actions = []
            batch_states = []
            batch_counter = 1
                
            # Print running average
        print("\rEp: {} Average of last 10: {:.2f}".format(
            ep + 1, np.mean(total_rewards[-10:])))
                
    return total_rewards

rewards = reinforce(env, pe)
window = 10
smoothed_rewards = [np.mean(rewards[i-window:i+1]) if i > window
                    else np.mean(rewards[:i+1]) for i in range(len(rewards))]

plt.figure()
plt.plot(rewards)
plt.plot(smoothed_rewards)
plt.ylabel('Total Rewards')
plt.xlabel('Episodes')
plt.show()

