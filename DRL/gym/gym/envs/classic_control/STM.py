"""
author: Bai Liping
email: 1218053408@njupt.edu.cn
version: v1.0
"""

import math
import numpy as np

class STMEnv(object):
    """
    Description:
        constant current controlled Scanning Tunneling Microscope Tip, the objective is to control a STM tip which is non-linear with respect to voltage given.

    Observation: 
        Num	Observation                 Min         Max
        0	Current                   -4.8            4.8
        1	Changes in Current        -Inf            Inf
        
    Actions:
        np.linspace(-100,100,10000)
    Reward:
        for every step taken, if the current remain constant, reward=0
                              if the current increases, reward=abs(increased amount)
                              if the current decreses, reward=abs(decresed amount)
    Starting State:
        episode start with current equals to the desired current level

    Episode Termination:
        entire scanning sample is a 28*28 2D grid with 'sample shape' on it.
        an episode terminates when the 28*28 grid is stepped over
    """

    def __init__(self):
        self.state=(0,0)
        self.grid_position=0
        np.random.seed(1)
        self.grid=np.random.rand(100)
        self.current=0
        self.nA=10000
                
    def grid_step(self):
        #first move one step on the grid position
        self.grid_position+=1
        self.sample_height=self.sample[self.grid_position]
        self.current=custom_current_function(self.sample_height+self.tip_height)
    
    def get_nA(self):
        return self.nA

    def step(self,action):
        current=self.current
        adjustment=custom_adjustment_function(action)
        self.tip_height+=adjustment
        self.current=custom_current_function(self.sample_height+self.tip_height)
        current_change=current-self.current
        reward=abs(self.current-self.target_current)
        self.state=(self.current,current_change)
        return self.state,reward

    def reset(self):
        self.state=(0,0)
        self.grid_position=0
        return np.array(self.state)

    def _custom_current_function()
    def _custom_reward_function()
