import numpy as np
import tensorflow as tf
from STMEnv import STMEnv
import matplotlib.pyplot as plt
np.random.seed(2)
tf.set_random_seed(2)  # reproducible

# Superparameters
MAX_EPISODE = 1000
MAX_EP_STEPS = 100   # maximum time step in one episode
GAMMA = 0.9     # reward discount in TD error
LR_A = 0.1    # learning rate for actor
LR_C = .1     # learning rate for critic

env = STMEnv()

N_F = 2
N_A = env.get_nA()


class Actor(object):
    def __init__(self, sess, n_features, n_actions, lr=LR_A):
        self.sess = sess

        self.s = tf.placeholder(tf.float32, [1, n_features], "state")
        self.a = tf.placeholder(tf.int32, None, "act")
        self.td_error = tf.placeholder(tf.float32, None, "td_error")  # TD_error

        with tf.variable_scope('Actor'):
            l1 = tf.layers.dense(
                inputs=self.s,
                units=n_actions,    # number of hidden units
                activation=tf.nn.relu,
                kernel_initializer=tf.random_normal_initializer(0., .2),    # weights
                bias_initializer=tf.constant_initializer(0.1),  # biases
                name='l1'
            )

            l2=tf.layers.dense(
                    inputs=l1,
                    units=n_actions,
                    activation=tf.nn.relu,
                    kernel_initializer=tf.random_normal_initializer(0.,.2),
                    name='l2'
                    )

            self.acts_prob = tf.layers.dense(
                inputs=l2,
                units=n_actions,    # output units
                activation=tf.nn.softmax,   # get action probabilities
                kernel_initializer=tf.random_normal_initializer(1/n_actions, .01),  # weights
                bias_initializer=tf.constant_initializer(0.1),  # biases
                name='acts_prob'
            )

        with tf.variable_scope('exp_v'):
            log_prob = tf.log(self.acts_prob[0, self.a])
            log_prob_clip=tf.clip_by_value(log_prob,1e-10,1-1e-10)
            self.exp_v = tf.reduce_mean(log_prob_clip * self.td_error)  # advantage (TD_error) guided loss

        with tf.variable_scope('train'):
            self.train_op = tf.train.AdamOptimizer(lr).minimize(-self.exp_v)  # minimize(-exp_v) = maximize(exp_v)

    def learn(self, s, a, td):
        s = s[np.newaxis, :]
        feed_dict = {self.s: s, self.a: a, self.td_error: td}
        _, exp_v = self.sess.run([self.train_op, self.exp_v], feed_dict)
        return exp_v

    def choose_action(self, s):
        s = s[np.newaxis, :]
        probs = self.sess.run(self.acts_prob, {self.s: s})   # get probabilities for all actions
        #print(probs)
        return np.random.choice(np.arange(probs.shape[1]), p=probs.ravel())   # return a int


class Critic(object):
    def __init__(self, sess, n_features, lr=LR_C):
        self.sess = sess

        self.s = tf.placeholder(tf.float32, [1, n_features], "state")
        self.v_ = tf.placeholder(tf.float32, [1, 1], "v_next")
        self.r = tf.placeholder(tf.float32, None, 'r')

        with tf.variable_scope('Critic'):
            l1 = tf.layers.dense(
                inputs=self.s,
                units=64,  # number of hidden units
                activation=tf.nn.relu,  # None
                # have to be linear to make sure the convergence of actor.
                # But linear approximator seems hardly learns the correct Q.
                kernel_initializer=tf.random_normal_initializer(0., .1),  # weights
                bias_initializer=tf.constant_initializer(0.1),  # biases
                name='l1'
            )
            l2=tf.layers.dense(
                    inputs=l1,
                    units=32,
                    activation=tf.nn.relu,
                    kernel_initializer=tf.random_normal_initializer(0.,.1),
                    name='l2'
                    )

            self.v = tf.layers.dense(
                inputs=l2,
                units=1,  # output units
                activation=None,
                kernel_initializer=tf.random_normal_initializer(0., .1),  # weights
                bias_initializer=tf.constant_initializer(0.1),  # biases
                name='V'
            )

        with tf.variable_scope('squared_TD_error'):
            self.td_error = self.r + GAMMA * self.v_ - self.v
            self.loss = tf.square(self.td_error)    # TD_error = (r+gamma*V_next) - V_eval
        with tf.variable_scope('train'):
            self.train_op = tf.train.AdamOptimizer(lr).minimize(self.loss)

    def learn(self, s, r, s_):
        s, s_ = s[np.newaxis, :], s_[np.newaxis, :]

        v_ = self.sess.run(self.v, {self.s: s_})
        td_error, _ = self.sess.run([self.td_error, self.train_op],
                                          {self.s: s, self.v_: v_, self.r: r})
        return td_error


sess = tf.Session()

actor = Actor(sess, n_features=N_F, n_actions=N_A, lr=LR_A)
critic = Critic(sess, n_features=N_F, lr=LR_C)     # we need a good teacher, so the teacher should learn faster than the actor

sess.run(tf.global_variables_initializer())
reward_log=[]

print('training')
for i_episode in range(MAX_EPISODE):
    s = env.reset()
    track_r = 0
    for step in range(100):
        s=env.grid_step()
        a = actor.choose_action(s)
        s_, r = env.step(a)
        track_r+=r
        td_error = critic.learn(s, r, s_)  # gradient = grad[r + gamma * V(s_) - V(s)]
        actor.learn(s, a, td_error)     # true_gradient = grad[logPi(s,a) * td_error]

    print("episode:", i_episode, "  reward:", track_r)
    reward_log.append(track_r)
print('done training')
plt.scatter(range(MAX_EPISODE),reward_log)
plt.show()

for i in range(3):
    s=env.reset()
    track_r=0
    for step in range(100):
        s=env.grid_step()
        a=actor.choose_action(s)
        s_,r=env.step(a)
        track_r+=r
        td_error=critic.learn(s,r,s_)
        actor.learn(s,a,td_error)
print(track_r)



