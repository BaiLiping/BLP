from agent import Agent
from env import PhasedArrayEnv
from policy_estimator import Policy_Estimator
from value_estimator import Value_Estimator
#import plot

def main():
    num_episode=
    gamma=
    beta=
    discount_rate=
    env=PhasedArrayEnv()

    agent=Agent(env,num_episode,gamma,beta,discount_rate)
    data1=agent.ac()
    data2=agent.td()
    data3=agent.mc()

    plot(data1,data2,data3)

if __name__=='__main__':
    main()
