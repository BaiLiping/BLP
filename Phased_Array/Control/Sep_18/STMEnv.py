"""
author: Bai Liping
email: 1218053408@njupt.edu.cn
version: v1.0
"""

import math
import numpy as np

def custom_sig(x):
    return 10*(1/(1+math.exp(x*0.03)))

def custom_current(x):
    try:
        ans=math.exp(0.01*x)
    except OverflowError:
        ans=float('inf')
    return ans

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
        self.grid=4.5*np.random.normal(0,0.5,100)
        self.grid[0]=0
        self.grid_height=self.grid[self.grid_position]
        self.nA=100
        self.tip_height=5
        self.target_current=custom_current(self.grid_height+self.tip_height)
        self.current=self.target_current
        self.current_difference=0
                
    def grid_step(self):
        #first move one step on the grid position
        self.grid_position+=1
        self.grid_height=self.grid[self.grid_position-1]
        self.current=custom_current(self.grid_height+self.tip_height)
        self.current_difference=self.current-self.target_current
        self.state=(self.current,self.current_difference)
        return np.array(self.state)
    
    def get_nA(self):
        return self.nA

    def step(self,action_index):
        action_choice=np.linspace(-100,100,self.nA)
        action=action_choice[action_index]
        adjustment=custom_sig(action)
        self.tip_height+=adjustment
        self.current=custom_current(self.grid_height+self.tip_height)
        reward=-abs(self.current-self.target_current)
        self.current_difference=self.current-self.target_current
        self.state=(self.current,self.current_difference)
        return np.array(self.state),reward

    def reset(self):
        self.state=(0,0)
        self.grid_position=0
        self.grid_height=self.grid[self.grid_position]
        self.tip_height=5
        self.target_current=custom_current(self.grid_height+self.tip_height)
        self.current=self.target_current
        self.current_difference=0
    
        return np.array(self.state)
