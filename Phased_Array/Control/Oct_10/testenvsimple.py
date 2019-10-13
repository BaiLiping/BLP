from envsimple import PhasedArrayEnv
import numpy as np
import matplotlib.pyplot as plt
np.random.seed(1)

env=PhasedArrayEnv()
state=env.reset()
plt.ion()
plt.show()
for i in range(8):
    s,r=env.step(0)
    print(s)
    print(r)
    env.plot_wave(str(i))
    plt.pause(0.1)
#plt.legend()
plt.savefig('simple_phased_outcome')
plt.ioff()
env.render()
