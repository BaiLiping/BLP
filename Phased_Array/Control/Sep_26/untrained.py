from env import PhasedArrayEnv
import numpy as np
import matplotlib.pyplot as plt

env=PhasedArrayEnv()
nA=env.get_nA()
gamma=0.9
reward_memory=[]
for i in range(100):
    s=env.reset()
    reward=0
    action_memory=[]
    for t in range(10):
        a=np.random.choice(np.arange(nA))
        while True:
            if a in action_memory:
                a=np.random.choice(np.arange(nA))
            else:
                action_memory.append(a)
                break
        s_,r=env.step(a)
        reward+=gamma*r
        s=s_
    reward_memory.append(reward)
    print('episode {} gained reward {}'.format(i,reward))
    env.render()

plt.scatter(range(100),reward_memory)
plt.show()


