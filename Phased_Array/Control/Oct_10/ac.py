import numpy as np
import tensorflow as tf
from envsimple import PhasedArrayEnv
import matplotlib.pyplot as plt
import pickle

np.random.seed(1)
tf.set_random_seed(1)

# Superparameters
MAX_EPISODE = 1000
MAX_STEPS = 8   # maximum time step in one episode
GAMMA = 1     # reward discount in TD error
LR_A = .1    # learning rate for actor
LR_C = .1    # learning rate for critic

env = PhasedArrayEnv()
env.reset()

N_F = env.get_nS()
N_A = env.get_nA()


class Actor(object):
    def __init__(self, sess, n_features, n_actions, lr=LR_A):
        self.sess = sess
        self.state = tf.placeholder(tf.float64, [1, n_features], "state")
        self.action = tf.placeholder(tf.int32, None, "action")
        self.td_error = tf.placeholder(tf.float64, None, "td_error")  

        with tf.variable_scope('Actor'):
            l1 = tf.layers.dense(inputs=self.state,units=16,activation=tf.nn.relu,name='l1')
            l4=tf.layers.dense(inputs=l1,units=n_actions,activation=tf.nn.relu,name='l4')
            action_probability_unclipped=tf.nn.softmax(l4,name='action_probability_unclipped')
            self.action_probability = tf.clip_by_value(action_probability_unclipped,1e-10,1-1e-10,name='action_probbability')

        with tf.variable_scope('policy_loss'):
            log_prob = tf.log(self.action_probability[0])
            self.policy_loss = tf.reduce_mean(log_prob * self.td_error) 
        with tf.variable_scope('train'):
            self.train_op = tf.train.AdamOptimizer(lr).minimize(-self.policy_loss)
    def learn(self, state, action, td_error):
        state = state[np.newaxis, :]
        feed_dict = {self.state: state, self.action: action, self.td_error: td_error}
        _, policy_loss = self.sess.run([self.train_op, self.policy_loss], feed_dict)
        return policy_loss

    def choose_action(self, state):
        state = state[np.newaxis, :]
        probs = self.sess.run(self.action_probability, {self.state: state}) 
        print(probs[0])
        return np.random.choice(np.arange(probs.shape[1]), p=probs[0])

class Critic(object):
    def __init__(self, sess, n_features, lr=LR_C):
        self.sess = sess
        self.state = tf.placeholder(tf.float64, [1, n_features], "state")
        self.v_next = tf.placeholder(tf.float64, [1, 1], "v_next")
        self.reward = tf.placeholder(tf.float64, None, 'reward')

        with tf.variable_scope('Critic'):
            l1 = tf.layers.dense(inputs=self.state,units=16,activation=tf.nn.relu,name='l1')
            self.v = tf.layers.dense(inputs=l1,units=1,activation=None,name='V')

        with tf.variable_scope('squared_TD_error'):
            self.td_error = self.reward + self.v_next - self.v
            self.loss = tf.square(self.td_error)
        with tf.variable_scope('train'):
            self.train_op = tf.train.AdamOptimizer(lr).minimize(self.loss)

    def learn(self, s, r, s_):
        s, s_ = s[np.newaxis, :], s_[np.newaxis, :]
        v_next = self.sess.run(self.v, {self.state: s_})
        td_error, _ = self.sess.run([self.td_error, self.train_op],{self.state: s, self.v_next: v_next, self.reward: r})
        return td_error


sess = tf.Session()

actor = Actor(sess, n_features=N_F, n_actions=N_A, lr=LR_A)
critic = Critic(sess, n_features=N_F, lr=LR_C)
sess.run(tf.global_variables_initializer())
saver=tf.train.Saver()

reward_log=[]

print('training')
for i_episode in range(MAX_EPISODE):
    s = env.reset()
    total_reward = 0
    for step in range(MAX_STEPS):
        a = actor.choose_action(s)
        s_, r = env.step(a)
        td_error = critic.learn(s, r, s_)  
        actor.learn(s, a, td_error)     
        s = s_
        total_reward+=r
    #env.render()
    print('episode {} has reward {}'.format(i_episode,total_reward))
    print(s)
    reward_log.append(total_reward)
print('done training')
plt.plot(range(MAX_EPISODE),reward_log)
plt.savefig('result')
plt.show()
saver.save(sess,'./saved_network')
with open('saved_result.pickle','wb') as wfile:
    pickle.dump(reward_log,wfile)

