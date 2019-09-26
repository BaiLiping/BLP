import pickle
import matplotlib.pyplot as plt

with open('saved_data.pickle','rb') as rfile:
    reward_list=pickle.load(rfile)

length=len(reward)
x=np.arange(length)
plt.plot(x,reward_list)
plt.show()
plt.savefile('after_training.png')
