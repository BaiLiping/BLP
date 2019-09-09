from env import PhasedArrayEnv
import numpy as np
import sys

def main():
    action=np.zeros(48*5)
    action[15]=1
    env=PhasedArrayEnv()
    env.reset()
    env.step(action)
    env.render()
    action=np.zeros(48*5)
    action[84]=1
    env.step(action)
    env.render()


if __name__==('__main__'):
    main()

