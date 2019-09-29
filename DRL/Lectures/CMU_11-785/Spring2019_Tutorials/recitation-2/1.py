'''
Pytorch is a python framework for machine learning, automatic differentialtion
'''
import torch
import numpy as np
import torch.nn as nn
'''
x=torch.FloatTensor(2,3)
print(x)
x.zero_()
print(x)

# Create uninitialized tensor
x = torch.FloatTensor(2,3)
print(x)
# Initialize to zeros
x.zero_()
print(x)

torch.manual_seed(123)
x=torch.randn(2,3)
print(x)
x_np=x.numpy()
print(x_np)
print(torch.eye(3))
print(torch.ones(2,3))
print(torch.zeros(2,3))
print(torch.arange(8))
print(torch.arange(3,7))
x=torch.FloatTensor(3,4)
print(x.size())
print(x.type())
x=torch.arange(0,5)
print(torch.sum(x))
print(torch.sum(torch.exp(x)))
print(torch.mean(x))

x=torch.arange(0,5)
print(torch.sum(x))
print(torch.sum(torch.exp(x)))
print(torch.mean(x))
x=torch.rand(3,2)
print(x)
print(x[1,:])
'''

x=torch.rand(3,5)
y=torch.rand(5,4)
try:
    z=torch.mm(x,y)
    print(z)

except TypeError as e:
    print(e)




