import numpy as np
import math
import matplotlib.pyplot as plt

x=np.linspace(-100,100,10000)
def custom_sig(x):
    return 10*(0.5-(1/(1+math.exp(x*0.03))))
y=[custom_sig(n) for n in x]
plt.plot(x,y)
plt.show()
