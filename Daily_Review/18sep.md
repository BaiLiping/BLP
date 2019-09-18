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

10. why the stock market data are oscillation, does that mean there is some underlining feedback stuff going on? Maybe the entire state of economy can be discribed as a dymanically adapting sytems function, and the impulse inputs are things such as Iranian attack on Saudi oil production. 

Everything in the systems equation seems to be positive feedback, there is are very few negatively feeding components. For instance, by the time economy is good, even people with the least to contribute can access credits. 

what does the ultimate economy looks like? is it possible that there is a size limit to economies? Maybe there isn't if the definition of economic activity being "producing something that others would find value in it". Is economy really all about employment? But maybe there is a more realistic interpretation of economy? get the smart people to work on problems that actually matters.

11. entroy as a measurement of orderedness. when Shannon started his question for a thoretically description of communication, he was asking himself, what exactly are people sending through communication channels. The obvious answer would be words, but entropy is the higher abstraction, words is just an encoding system.

So, under a known encoding system(language is just one of them, and most definitively not the most effective one), what you are piping through communication channels are constraints, such that the possible interpretations narrows down.

Communication channels are noisy. But with the right formulation, there would st
ill be a way to pipe that constraint through.



12. reason backward(fermilization). off-label use(hijack a design, utilizing the features for other purposes). sequential/stochastic/statistical thinking.(best illustrated by the sego game/decision under uncertainties/strategy should not be limited to an one time act, but can be a sequence of acts). balancing act (be aware of the limitations baked into the system, in the meantime, don't make the environment the scapegoat for your incompetence). pushing one factor to the extreme/the proper proportion over all the factors. 

    

13. decompose a complicated problem into tractable components; follow a line of reasoning for as long as your brain is capable of; if I were to tackle a problem today, what are the tools at my disposal?

    

14. when do i know i have a firm grasp on that concept:
    there is an abstract description of that concept, also a motivation and a luminating example.

15. review of c and cpp:

    malloc() allocate in the heap side of the memory, when allocated memory must manage it

    '*' pointer, essentially an address in cpp, that idea of pointer has really become much more complicated, when you want to read the content of that pointer, you dereference it &name returns the address of that name

    a more complicated use would be * void, the pointer to a function

    char[] is a string, with the ending /0

    struct name_of the struct{

    ​     name:

    ​     other:

    }

    when a struct is created, the allocation on memory can be visualized

    ** pointer of pointer

    &leftreference &&rightreference   one of those is for moving, only reference to it once

    '+' is a operator short hander, is equivolent to add(x,y)

    all those symbols can be over loaded

    cpp is an object oriented language, inheritance, vtable, are the low level implementations to facilitate those features

    class name of the class{

    public:

    variables:

    methods()

    constructors()

    desconstructors()

    private:

    }

    smart pointers are introduced in cpp11 to help with the constructor, deconstructor (memory management)

    for both c and cpp there would be a header file and then a implementation file

    dynamically linked, .so file, to .h file usually placed at /usr/lib

    objected oriented programming in C is possible, but it involves managing pointers to functions and that process is error prone.

16. for python, the modulization and packaging is quite simple, just say import

17. 'init and call constructor can be easily understood if you think about its implementation

18. 