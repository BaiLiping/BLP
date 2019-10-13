import numpy as np
import math
import sys
import matplotlib.pyplot as plt

wave_length=2
division=40
vertical_distance=2
phase=math.pi
weight=100
omega=math.pi/(division/2)
distance_magnification=1
def generate_target():
    index=np.random.choice(range(48))
    position=np.unravel_index(index,(8,6))
    print(position)
    return position
    
def location_info(wave,target_location):
    for t in range(division):
        impact_t=math.cos((omega*t)
        wave[t]=impact_t*weight
    magnitute=np.max(wave)
    return wave,magnitute
        
def compute_additive_wave(x,y,p,wave,target_location):

    for t in range(division):
        impact_t=math.cos(omega*t+math.pi*p)
        wave[t]+=impact_t*weight
    magnitute=np.max(wave)
    return wave,magnitute

class PhasedArrayEnv(object):
    def __init__(self):
        self.nA=6
        self.x=1
        self.y=0
        self.record=[]
        self.wave=np.zeros(division)
        self.target_location=generate_target()
        self.wave,self.target_info=location_info(self.wave,self.target_location)
        self.mag=self.target_info
        self.state=np.array((self.x,self.y))
        self.nS=len(self.state)

    def reset(self):
        #self.target_location=generate_target()
        self.x=1
        self.y=0
        self.record=[]
        self.wave=np.zeros(division)
        #self.target_location_info=location_info(self.target_location)
        self.wave,self.target_info=location_info(self.wave,self.target_location)
        self.mag=self.target_info
        self.state=np.array((self.x,self.y))
        return self.state
    
    def get_nA(self):
        return self.nA

    def get_nS(self):
        return self.nS

    def step(self,action):
        old_mag=self.mag
        self.wave,self.mag=compute_additive_wave(self.x,self.y,action,self.wave,self.target_location)
        if self.x==7:
            self.x=0
            self.y+=1
        else:
            self.x+=1
        self.record.append(action)
        mag_addition=self.mag-old_mag
        self.state=(self.x,self.y)
        return np.array(self.state),mag_addition

    def plot_wave(self,label):
        x=np.arange(division)
        plt.plot(x,self.wave,label=label)
        
    
    def render(self):
        outfile=sys.stdout
        output='0  '
        outfile.write(output)

        for i in range(47):
            position=np.unravel_index(i+1,(8,6))
            output='  '
            output+=str(self.record[i])
            output+='  '
    
            if position[1]==0:
                output=output.lstrip()
            if position[1]==5:
                output=output.rstrip()
                output+='\n'
            outfile.write(output)
        outfile.write('\n')
