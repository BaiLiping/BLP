from envsimple import PhasedArrayEnv
import numpy as np
import matplotlib.pyplot as plt
np.random.seed(1)

env=PhasedArrayEnv()
state=env.reset()
plt.ion()
plt.show()
for i in range(8):
    s,r=env.step(np.random.choice(np.arange(6)))
    print(s)
    print(r)
    env.plot_wave(str(i))
    plt.pause(0.1)
#plt.legend()
plt.savefig('phased_outcome')
plt.ioff()
env.render()
