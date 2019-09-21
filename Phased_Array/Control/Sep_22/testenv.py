from env import PhasedArrayEnv
import numpy as np
import matplotlib.pyplot as plt
np.random.seed(1)

env=PhasedArrayEnv()
state=env.reset()
print(state)
plt.ion()
env.plot_wave('test')
plt.show()
for i in range(46):
    s,r=env.step(np.random.choice(np.arange(6)))
    #s,r=env.step(4)
    #s,r=env.step(0)
    env.plot_wave(str(int(i)))
    plt.pause(1)
    print(s)
    print(r)
#plt.legend()
plt.savefig('phased_outcome')
plt.ioff()
