import numpy as np
import math
import sys
wave_length=10
phase=math.pi/5
weight=1

def generate_target():
    index=np.random.choice(range(48))
    position=np.unravel_index(index,(8,6))
    return position
    
def location_info(target_location):
    distance=math.sqrt(pow((3*(target_location[0])),2)+pow(3*(target_location[1]),2))
    impact=(1/(distance+1))*30*math.cos(distance/wave_length)
    return impact*weight
        
def compute_reward(x,y,p,target_location):
    distance=math.sqrt(pow((3*(x-target_location[0])),2)+pow(3*(y-target_location[1]),2))
    reward=(1/(distance+1))*30*math.cos(distance/wave_length*(2*math.pi)+(p-1)*phase)
    return reward

class PhasedArrayEnv(object):
    def __init__(self):
        self.nA=5
        self.x=1
        self.y=0
        self.record=[]
        self.reward=0
        self.total_reward=0
        self.target_location=generate_target()
        self.target_location_info=location_info(self.target_location)
        self.state=(self.target_location,self.x,self.y,self.total_reward)
    def reset(self):
        #self.target_location=generate_target()
        self.reward=0
        self.x=1
        self.y=0
        self.record=[]
        self.total_reward=0
        #self.target_location_info=location_info(self.target_location)
        self.state=(self.target_location_info,self.x,self.y,self.total_reward)
        return np.array(self.state)
    
    def get_nA(self):
        return self.nA

    def step(self,action):
        if self.x==7:
            self.x=0
            self.y+=1
        else:
            self.x+=1
        self.record.append(action)
        self.reward=weight*compute_reward(self.x,self.y,action,self.target_location)
        self.total_reward+=self.reward
        self.state=(self.target_location_info,self.x,self.y,self.total_reward)
        return np.array(self.state),self.reward
    
    def render(self):
        outfile=sys.stdout
        output='0  '
        outfile.write(output)

        for i in range(47):
            position=np.unravel_index(i+1,(8,6))
            output='  '
            output+=str(self.record[i]+1)
            output+='  '
    
            if position[1]==0:
                output=output.lstrip()
            if position[1]==5:
                output=output.rstrip()
                output+='\n'
            outfile.write(output)
        outfile.write('\n')
