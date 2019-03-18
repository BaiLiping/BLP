1. shell:
the starting line of shell script is #!bin/bash to indicate where to locate the binary file for this. Shell is a software enviroment on top of Linux Kernel, it is used to interact with the operating system, querry its state. People use shell script to manage linux based server project.

2. the linux booting process and gcc
linux, in its current form, has around 10 million line of code. GCC has roughly 6 million. Both of those industrial/commercial software can not be understood by tracing specific funtions, a new, visualization method is called for. 

3. different containers:
vector<int> queue<int> stack<int>, the choice of container to use should be based upon the oprations required for that particular algorithm.

4. At its core, the most important skillset underlying computer science:
ability to see things through, through the jagon, the technique. Visualizing how a particular process would pan out and if that is the most effecient rendering to get that target.

5. target for today, heap, hashtable, graph, operator definition.

6. not too effecient experiments from last week:
cpp conference: there are quite a lot techniques and specifics associated with the language of cpp, such as consexpr, meta programing, and various alias and its related efficacy. Cpp Conference the venue where those experiences are shared. there are two groups of talks in particular:
a) Sean Parent, better code series, it would soon become a book:
Regular Types: Goal: No Incomplete Types;
Algorithms: Goal: No Raw Loops(know the container function and algorithm function);
Data Structure: Goal: No Incidental Data Structure;
Runtime Polymorphism: Goal: No Inheritance, no raw pointer;
Concurrency: Goal: No Raw Synchronization Primitives;


what is regular type?
an object is an entity stored in memory
a type is a pattern for storing and modifying objects

Another one is Scott Meyers effective cpp series. 

Both of those books are bit too advanced for me at this point, and they would definitly need to be revisited at when my interaction with cpp is a bit more substaintial. 

few things I should pay attention to:
initialization and construction.
Every type has a default constructor, somehow, initialization would be more economical than constractor, why?
which syntax refers to initialization?
void function():data(d), left(l){} this is initialization but not construction
++j;

the properties of an object, symmetry, reflexitivity, commutivity,
 if representation of an object is not unique, 
tty: teletype, in Linux, there are two types of memory, block and char, block mean for files, char means interfacing components, ie, screen, keyboard, mouse.


7. usr/bin all the binary files
usr/include all the header files
usr/lib symbolic links
for instance readlink lGL.so
then it would show you where the lGL.so is symbolically liked to. 
this symbolic linked is used during compilation:
g++ -lGL -lGLU -lglut those three flags tell the compiler to search for usr/lib, find there those three flags are linked to, the .so files. and then put those .so files here. for instance, -lGL.so might be symbolically liked to GraphicLib.so in usr/bin
then it is equivolent of saying:
g++ /usr/bin/GraphicLib.so main.cpp
technically, I should be able to write my own library:
eg. I've write BLP.cpp, 
g++ -c BLP.cpp -o BLP.so
put BLP.so to usr/bin and create BLP.so symbolic link at usr/lib
when compile 
g++ -BLP main.cpp it should put the BLP.so file directly there.:

