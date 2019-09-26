import matplotlib
import numpy as np
import tensorflow as tf
import collections
from env import PhasedArrayEnv

matplotlib.style.use('ggplot')
env=PhasedArrayEnv()
nA=env.get_nA()
nS=env.get_nS()
Alpha=0.9
Beta=0.9
Gamma=1

class PolicyEstimator():
    def __init__(self,scope='PolicyEstimator'):
        with tf.variable_scope(scope):
            self.state=tf.placeholder(tf.float32,[],'state')
            self.action=tf.placeholder(tf.int32,'action')
            self.target=tf.placeholder(tf.float32,'target')

            l1=tf.layers.dense(inputs=self.state,units=512,activation=tf.nn.relu,kernel_initializer=tf.random_normal(0.,.1),name='l1')
            self.action_probability=tf.layers.dense(inputs=l1,units=nA,activation=tf.nn.softmax,kernel_initializer=tf.random_normal(0.,.1),name='action_prob')
            
