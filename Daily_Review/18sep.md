1. maximum entropy reinforcement learning:
entropy is a numerical abstraction that describes 'structureness' of the model.
If we have absolutely no information on the model distribution, then we should assume uniform distribution over all elements, hence the entropy is maximized.

When constraints are applied to the model distribution, more structure can be erected, yet, if the number of constraints is less than the numebr of elements, then there would still be a degree of guessing. Maximum Entropy learning is a way to guide the guess work. 

In the same vein, maximum entropy, maximum likelihood, are abstructions of a heuristic. For entropy, is the 'structureness', for likelihood is that sense of 'uncertainty interval'. with that numerical abstraction, then we can do optimization when there isn't enough constraints to fully define the problem.

2. logistics regression and softmax regression. They are basically the same.(somehow related to both maximum entropy learning and maximum likelihood learning)

3. pass multiple arguments in python
def name_of_function(regular_argument, *arg=a list of arguments,**kwarg=key word arg, send in the arguments as a dictionary) *

4. * dfd* with tf.Session() as sess, sess.run(op(variable,assignment))

5. tf.assign(variable, value)

6. in tf basically there is no "+ -" as a handle, they use the names instead

7. in tf, define the graph first, which consist of:
constants: tf.constant()
variables: tf.Variable(),tf.get_variable() this is to create a new variable out of existing variable.
for variables, one consideration would be scope: variable_scope('name_of_the_scope') this is particularly useful if you need to fetch information about a particular network
tf.placeholder(dtype,shape)

8. after the graph is defined, define the operations on that graph
tf.layers.dense(.....)
tf.nn.softmax(x)

9. after defined both the graph and the operations, open up a session to actually do the compuation. Data are fed into the graph at this point of time.
with tf.Session() as sess:
sess.run(opration1,feed_dict={tf_x:x,tf_y=y})
