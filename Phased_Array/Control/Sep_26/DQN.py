import tensorflow as tf
import numpy as np
from envDQN import PhasedArrayEnv
import matplotlib.pyplot as plt
import pickle

tf.set_random_seed(1)
np.random.seed(1)

# Hyper Parameters
MAX_EPISODES=10000000
MAX_STEPS=48
BATCH_SIZE = 2000
LR = 0.01                   # learning rate
EPSILON=0.9
GAMMA = 1                 # reward discount
TARGET_REPLACE_ITER = 100   # target update frequency
MEMORY_CAPACITY = 20000
MEMORY_COUNTER = 0          # for store experience
LEARNING_STEP_COUNTER = 0   # for target updating
env=PhasedArrayEnv()
N_ACTIONS = env.get_nA()
N_STATES = env.get_nS()
MEMORY = np.zeros((MEMORY_CAPACITY, N_STATES * 2 + 2))     # initialize memory

# tf placeholders
tf_s = tf.placeholder(tf.float64, [None, N_STATES])
tf_a = tf.placeholder(tf.int32, [None, ])
tf_r = tf.placeholder(tf.float64, [None, ])
tf_s_ = tf.placeholder(tf.float64, [None, N_STATES])

with tf.variable_scope('q_eval'):
    l1_eval = tf.layers.dense(tf_s, 512, tf.nn.relu, kernel_initializer=tf.random_normal_initializer())
    l2_eval=tf.layers.dense(l1_eval,128,tf.nn.relu,kernel_initializer=tf.random_normal_initializer())
    l3_eval=tf.layers.dense(l2_eval,64,tf.nn.relu,kernel_initializer=tf.random_normal_initializer())
    q = tf.layers.dense(l3_eval, N_ACTIONS, kernel_initializer=tf.random_normal_initializer())
with tf.variable_scope('q_target'):
    l1_target = tf.layers.dense(tf_s_, 512, tf.nn.relu, trainable=False)
    l2_target=tf.layers.dense(l1_target,128,tf.nn.relu,trainable=False)
    l3_target=tf.layers.dense(l2_target,64,tf.nn.relu,trainable=False)
    q_next = tf.layers.dense(l3_target, N_ACTIONS, trainable=False)

q_target = tf_r + GAMMA * tf.reduce_max(q_next, axis=1)                   # shape=(None, ),
a_indices = tf.stack([tf.range(tf.shape(tf_a)[0], dtype=tf.int32), tf_a], axis=1)
q_target_a = tf.gather_nd(params=q, indices=a_indices)     # shape=(None, ), q for current state
loss = tf.reduce_mean(tf.squared_difference(q_target, q_target_a))
loss_clip=tf.clip_by_value(loss,1e-8,1000)
train_op = tf.train.AdamOptimizer(LR).minimize(loss_clip)

sess = tf.Session()
sess.run(tf.global_variables_initializer())
saver=tf.train.Saver()

def choose_action(s):
    s = s[np.newaxis, :]
    if np.random.uniform() < EPSILON:
        actions_value = sess.run(q, feed_dict={tf_s: s})
        print(actions_value[0])
        action = np.argmax(actions_value[0])
    else:
        action = np.random.choice(np.arange(N_ACTIONS))
    return action


def store_transition(s, a, r, s_):
    global MEMORY_COUNTER
    transition = np.hstack((s, [a, r], s_))
    # replace the old memory with new memory
    index = MEMORY_COUNTER % MEMORY_CAPACITY
    MEMORY[index, :] = transition
    MEMORY_COUNTER += 1


def learn():
    # update target net
    global LEARNING_STEP_COUNTER
    if LEARNING_STEP_COUNTER % TARGET_REPLACE_ITER == 0:
        t_params = tf.get_collection(tf.GraphKeys.MODEL_VARIABLES, scope='q_target')
        e_params = tf.get_collection(tf.GraphKeys.MODEL_VARIABLES, scope='q_eval')
        sess.run([tf.assign(t, e) for t, e in zip(t_params, e_params)])
    LEARNING_STEP_COUNTER += 1

    # learning
    sample_index = np.random.choice(MEMORY_CAPACITY, BATCH_SIZE)
    b_memory = MEMORY[sample_index, :]
    b_s = b_memory[:, :N_STATES]
    b_a = b_memory[:, N_STATES].astype(int)
    b_r = b_memory[:, N_STATES+1]
    b_s_ = b_memory[:, -N_STATES:]
    sess.run(train_op, {tf_s: b_s, tf_a: b_a, tf_r: b_r, tf_s_: b_s_})


reward_memory=[]
for i_episode in range(MAX_EPISODES):
    s = env.reset()
    ep_r = 0
    for step in range(MAX_STEPS):
        a = choose_action(s)
        # take action
        s_, r = env.step(a)

        store_transition(s, a, r, s_)

        ep_r += r
        if MEMORY_COUNTER > MEMORY_CAPACITY:
            learn()

        s = s_
    print('Ep: ', i_episode, '| Ep_r: ', ep_r)
    #env.render()
    reward_memory.append(ep_r)

print('done learning')
plt.plot(range(MAX_EPISODES),reward_memory)
plt.show()
plt.savefig('DQN.png')
saver.save(sess,'./saved_DQN_network')
with open('saved_DQN_result.pickle','wb') as wfile:
    pickle.dump(reward_memory,wfile)


