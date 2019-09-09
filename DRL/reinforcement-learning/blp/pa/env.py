import numpy as np
import math
import sys
wave_length=0.7
phase=180/5



def generate_target():
    index=np.random.choice(np.arange(48))
    position=np.unravel_index(index,(8,6))
    return position
    
def location_info(target_location):
    distance=math.sqrt(pow((3*(target_location[0])),2)+pow(3*(target_location[1]),2))
    impact=math.cos(distance/wave_length)
    return impact
        
def compute_impact(state,target_location):
    impact=0
    for i in range(len(state)):
        if i!=0:
            x=np.unravel_index(i,(8,6))[0]
            y=np.unravel_index(i,(8,6))[1]
            distance=math.sqrt(pow((3*(x-target_location[0])),2)+pow(3*(y-target_location[1]),2))
            impact+=math.cos(distance/wave_length+(state[i])*phase)
    return impact

class PhasedArrayEnv(object):
    def __init__(self):
        wave_length=0.7
        phase=180/5
        nA=47*5
        nS=48*47*6
        state=np.zeros(48)
        target_location=generate_target()
    
    def reset(self):
        self.target_location=generate_target()
        self.state=np.zeros(48)
        self.state[0]=location_info(self.target_location)
       #print(self.state[0])
       
    def step(self,action):
        action_index=np.argmax(action)
        impact=compute_impact(self.state,self.target_location)
        x=np.unravel_index(action_index,(8,6,5))[0]
        y=np.unravel_index(action_index,(8,6,5))[1]
        p=np.unravel_index(action_index,(8,6,5))[2]+1
        state_index=np.ravel_multi_index((y,x),(8,6))
        self.state[state_index]=p
        new_impact=compute_impact(self.state,self.target_location)
        reward=new_impact-impact
        return self.state,reward
    
    def render(self):
        outfile=sys.stdout
        for i in range(len(self.state)):
            position=np.unravel_index(i,(8,6))
            if self.state[i]!=0:
                output='  '
                output+=str(int(self.state[i]))
                output+='  '
            else:
                output='  _  '
    
            if position[1]==0:
                output=output.lstrip()
            if position[1]==(8,6)[1]-1:
                output=output.rstrip()
                output+='\n'
            outfile.write(output)
        outfile.write('\n')
