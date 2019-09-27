1. the taxotomy of control
a) just feedback components such as damper, friction, capacitance, inductance, or digitally induced feedback components with pwm

with feedback, the system would stabalize itself eventually, or it would just blow up. This is the simplest form of control

b) with rigid specifications. Real world use case for control comes with restrictions, they comes in two flavors:
 i) parameter search for specific rise time, overshoot, stabalize time
 ii) the restriction is imposed to the entire system such as fuel usage.this is the optimization question utalize calculus of variation, and lagrange multiplier

c) dynamic control. when the system is fixed, all it has to do is to react to input. Yet what happens if the system is dynamic? This is where the predictive control comes in.

d) how does learning fit into control theory?

2. PyTorch
1) the difference between PyTorch and Tensorflow. For tensorflow you first define a graph and the operations on that graph, and then you would open a session to feed data into the graph to do the actual computation. Benefit of this is that since the graph is defined already then you can better allocate resource.

For PyTorch, the graph is defined when a forward path is ran. This approach is simpler syntactically, also easier for control structure.

2) Basic structure of PyTorch code

i) Defining the net:
class Net(torch.nn.Module):
    def __init__(self):
        super().__init__
        self.fc1=torch.nn.Linear(input_dimmentioan, hidden_layer_dimmention)
        self.fc2=torch.nn.Linear(hidden_layer_dimmetion, out_dimmetion)

ii) define the forward path
     def forward(self,x):
         x=torch.relu(self.fc1.forward(x))
         x=torch.dropout(x,p=0.5)
         x=torch.sigmoid(self.fc.forward(x))
         return x

iii)optimizer:
net=Net()
optimizer=torch.optim.SGD(net.parameters())

iv)training:
for epoch in range(ddd):
    for kkkk 
    optimizer.zero_grad() make the gradient zero
    prediction=net.forward(dtat)
    loss=net.loss_fn(prediction, real)
    loss.backward()
    optimizer.step()

3. Python Decorators
the idea of decorator is that you can add functionality to a existing function without adapting the original function. Usally it is used for logger or timer. but here we can define our own function by adding to torch.autograd.function the decorator would be @staticmethod

when inherent from a base class, use super().__init__ to simplify the initialization.



