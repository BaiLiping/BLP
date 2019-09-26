import numpy as np
import tensorflow as tf
from env import PhasedArrayEnv
import matplotlib.pyplot as plt
import pickle

np.random.seed(1)
tf.set_random_seed(1)

# Superparameters
MAX_EPISODE = 1000000
MAX_EP_STEPS = 10   # maximum time step in one episode
GAMMA = 1     # reward discount in TD error
LR_A = .5    # learning rate for actor
LR_C = .5    # learning rate for critic

env = PhasedArrayEnv()
env.reset()

N_F = env.get_nS()
N_A = env.get_nA()


class Actor(object):
    def __init__(self, sess, n_features, n_actions, lr=LR_A):
        self.sess = sess
        self.state = tf.placeholder(tf.float32, [1, n_features], "state")
        self.action = tf.placeholder(tf.int32, None, "action")
        self.td_error = tf.placeholder(tf.float32, None, "td_error")  

        with tf.variable_scope('Actor'):
            l1 = tf.layers.dense(inputs=self.state,units=10,activation=tf.nn.relu,kernel_initializer=tf.random_normal_initializer(0., .2),bias_initializer=tf.constant_initializer(0.1),name='l1')
            self.action_probability = tf.layers.dense(inputs=l1,units=n_actions,activation=tf.nn.softmax,kernel_initializer=tf.random_normal_initializer(1/n_actions, .01),bias_initializer=tf.constant_initializer(0.1),name='action_probbability')

        with tf.variable_scope('exp_v'):
            log_prob = tf.log(self.action_probability[0, self.action])
            log_prob_clip=tf.clip_by_value(log_prob,1e-10,1-1e-10)
            self.exp_v = tf.reduce_mean(log_prob_clip * self.td_error) 
        with tf.variable_scope('train'):
            self.train_op = tf.train.AdamOptimizer(lr).minimize(-self.exp_v)
    def learn(self, state, action, td_error):
        state = state[np.newaxis, :]
        feed_dict = {self.state: state, self.action: action, self.td_error: td_error}
        _, exp_v = self.sess.run([self.train_op, self.exp_v], feed_dict)
        return exp_v

    def choose_action(self, state):
        state = state[np.newaxis, :]
        probs = self.sess.run(self.action_probability, {self.state: state}) 
        print(probs[0])
        return np.random.choice(np.arange(probs.shape[1]), p=probs[0])

class Critic(object):
    def __init__(self, sess, n_features, lr=LR_C):
        self.sess = sess
        self.state = tf.placeholder(tf.float32, [1, n_features], "state")
        self.v_next = tf.placeholder(tf.float32, [1, 1], "v_next")
        self.reward = tf.placeholder(tf.float32, None, 'reward')

        with tf.variable_scope('Critic'):
            l1 = tf.layers.dense(inputs=self.state,units=10,activation=tf.nn.relu,kernel_initializer=tf.random_normal_initializer(0., .1),bias_initializer=tf.constant_initializer(0.1),name='l1')
            self.v = tf.layers.dense(inputs=l1,units=1,activation=None,kernel_initializer=tf.random_normal_initializer(0., .1),bias_initializer=tf.constant_initializer(0.1),name='V')

        with tf.variable_scope('squared_TD_error'):
            self.td_error = self.reward + GAMMA * self.v_next - self.v
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
    track_r = 0
    for step in range(47):
        a = actor.choose_action(s)
        s_, r = env.step(a)
        track_r+=GAMMA*r
        td_error = critic.learn(s, r, s_)  
        actor.learn(s, a, td_error)     
        s = s_

    print("episode:", i_episode, "  reward:", track_r)
    env.render()
    reward_log.append(track_r)
print('done training')
plt.reward(range(MAX_EPISODE),reward_log)
plt.savefig('result')
plt.show()
saver.save(sess,'./saved_network')
with open('saved_result.pickle','wb') as wfile:
    pickle.dump(reward_log,wfile)

