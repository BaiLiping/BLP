import tensorflow as tf
import numpy as np
from matplotlib.pyplot import plot

'''
the big idea behind tensorflow
tensorflow is a framework composed of:
    a library of defining computational graphs
    a runtime for executing such a groh on variety of different hardware

computational graphs are an abstract way of describing computations as directed graphs:
    the edge correspond to multidimentional arrays(tensor)
    the node create or maniputate these tensors according the specific rules
'''



a=tf.constant(10)
b=tf.constant(20)

t1=tf.multiply(a,b)
t2=tf.add(a,b)
res=tf.divide(t1,t2)

#tf.Print(res)
'''
when you run this program, you only defined what exercusionis you would want to exercute, but it has not been exercuted, you just defined the graph, so to speak

actual exercusing of computational graph is a seperate step

tensorflow graphs supports very general forms of computation, including steateful, conditional, iterative and asynchronous computation. All these different forms of computation are supported thansk to a variety of build-in ops:
    variable ops: to read and update writable values that persist across exercutions
    conditional ops: to make part of the computation conditional on other parts
    loop ops: to allow to efficiently specify computational graphs with cycles
    control ops, to enforce an order in the exercusion of paris of ops
    queue ops, to describe asynchronous computations

'''
'''
Defition vs exercution

any tensorflow progarm is composed of two seperate parts:
    definition of the computational graph(tf.Graph)
    execution of the computational graph(tf.Session)
when we define the graph we make use of a set of tensorflow lib functions to specify some computation as a tf.graph, at execution time we use the tensorflow runtime to execute those computations through a tf.session


what is tf.Graph(just a description of that abstract structure)

describes computation through Ops and Tensors
a Tensor is a descrition of a multidimentinal array
tensor may have a shape and a data type but don't have any actual value(a abstraction of that data)
exampe:
    a=tf.zeros((int(ie12),int(ie12))) (there is no way that your computer would allocate that amount of resources to it, but it is perfectly fine for you to define such a thing abstractly)
    a=tf.zeros((10,10)) a.shape=10,10
    b.tf.concat([a,a],axix=0) b.shape=20,10 axis=0 means along the first axis

    shape inference is build in to tf

tf.Session
example:
    '''
#define the graph
a=tf.constant(1.0)
b=tf.constant(1.0)
c=tf.constant(4.0)
d=tf.div(tf.add(a,b),c)
    
#exercute the graph
with tf.Session() as session:
    #define a session object
    print(session.run(d))

'''
Session (tf.Session):
    carries out the actual computation as defined by the graph
    session.run(tensor) executes the graph and return the behaviour of the tensor
    session.run([tensor1, tensor2, tensor3.....]) computes the value of all the tensors in that list

the scheduling the the exercution etc is taken care of by the Session backend

execution model, when session.run() is called, TensorFlow identifies and executes the smallest set of nodes that needs to be evaluated in order to compute the requested tensor

tf is awere of all functional dependencies and additional dependencies can be added through special control ops. tf can schedule the exercution of ops which do not depend on each other in parallel across available cores, devices and machies

tf can be interfaced with multiple languages, however, those are just the instructions as of what kind of structure(graph) you want and what kind of operation you want to done with those graphs. The actual implementation of things are done in c++ backend

variables enable learning, by preserving state across execution of the graph
all trainable parameters of machine learning model are tf.Variables
A variable is defined by its name, type, shape and initalization procedure. 

v=tf.get_variable(
        "name",dtype=tf.float32,shape=[2,2],
        initializer =tf.random_normal_initializer(stddev=0.5))

y=tf.matmul(v,tf.constant([[1,2],[3,4]]))
increment_op=v.assign(v+1)
increment_op=tf.assign(v,v+1)
defining a variable adds the corresponding ops to the computational graph, but a variable instance exists and holds value in the context of a specific sesion, andy variable we define mst be explicitly initilized before its first used in a session you can initilaize all vairiable si n the graph at once


with tf.Session() as session:
    print(session.run(v))

'''
'''
create graph()
init=tf.global_variables_initilizer()
with tf.Session() as session:
    session.run(init)
print(init)
'''

'''
we often need a way to feed data into the graph if the dataset is very small we can, in principle, embd it in the graph definition, but this is not recommended

ideally, we want to seperate data from the definitin of a graph, enter, placeholder

use placeholders and feed dictionaries to inject data into the graph at execution time. Placeholders are used in the graph definition as tensors, but at each execution of the graph they will take the value specified in the deed dictionary provided to sesion.run

'''
a= tf.compat.v1.placeholder(tf.float32,[])
b=tf.constant(1.0)
c=a+b
with tf.Session() as session:
    print(session.run(c,feed_dict={a:3.0}))
    print(session.run(c,feed_dict={a:4.0}))


'''
placeholder pro and cons:
    using placeholder puts the onus on you to manage the data, TF expects a dictionary of numpy arrays for each call to session.run() the rest is up to you: load, pre-processing, batch, queue, etc, all can be done in python code.
    vary plexible, but sometimes can be labour intensive
    TF offers additional buildin features and functionalities for working with data, which you can't take advantage of if you use placeholder to manage your own data


'''

num_samples,w,b=20,0.5,2.
xs=np.asarray(range(num_samples))
ys=np.asarray([x*w+b+np.random.normal()
        for x in range(num_samples)])

class Linear_Regression_Model(object):
    def __init__(self):
        self.w=tf.compat.v1.get_variable("w",dtype=tf.float32,shape=[],initializer=tf.zeros_initializer())
        self.b=tf.compat.v1.get_variable("b",dtype=tf.float32,shape=[],initializer=tf.zeros_initializer())
    def __call__(self,x):
        return self.w*x+self.b

xtf=tf.compat.v1.placeholder(tf.float32,[num_samples],'xs')
ytf=tf.compat.v1.placeholder(tf.float32,[num_samples],'ys')
model=Linear_Regression_Model() #initialize the linear model with w, and b
model_output=model(xtf)

cov=tf.reduce_sum((xtf-tf.reduce_mean(xtf))*(ytf-tf.reduce_mean(ytf)))
var=tf.reduce_sum(tf.square(xtf-tf.reduce_mean(xtf)))
w_hat=cov/var
b_hat=tf.reduce_mean(ytf)-w_hat*tf.reduce_mean(xtf)

solve_w=model.w.assign(w_hat)
solve_b=model.b.assign(tf.reduce_mean(ytf)-w_hat*tf.reduce_mean(xtf))

with tf.Session() as sess:
    sess.run([solve_w,solve_b],feed_dict={xtf:xs, ytf:ys})
    preds=sess.run(model_output, feed_dict={xtf:xs, ytf:ys})

print((xs, ys))
print((xs,preds))
print(ys-preds)


