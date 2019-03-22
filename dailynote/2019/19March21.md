1. target for today is to understand various form of copy. do you need to allocate new space for a copied object or do you just have a new pointer point to the actual allocated space where the data is contained. what is the mechanism for reference counting?
another target is to understand heap, how is heap allocation of memory implemented. 
the third target is unique_ptr and shared_ptr

2. review on implementing object oriented programming with c:
first off, it is an abosultely excellent exercise. In reality, it is implemented partically in assembly, but c comes with it enough functionalities such that implementing oop with c can be achievable.This actually illustrate a fairly important principle in terms of learning. Don't wait until you have all the tool and skills to do somehtings. I don't think assembly language is something that I am gonna want to picup, yesterday, the exercise shapens my understanding of the
motivation for oop and my c specific skills. going forward, I
d like for this learning by doing mode be a norm. implementing datastructure, implementing algorithm, implementing rack.
3. struct nameofstruc {
    int data1;
    int data2;
    void (*operation1)(argument);
    void(*operation2)(argument);
}
//operation2 is the address of the function
//the following is the actual definition of function
void operation1 (argument1){
body of function
}
//later, you need to manually like nameofstructure.operation2 to operation2, they don't have to be the same name, you probably can define the function inside structure.

this concept is called encapsulation, basically, manual linking of function pointer to function address is done automatically.
4, inheritance
struct nameofstructure2{
struct nameofstructure1;
extra data and operation
}
5. vtable and vptr: this is the mechanism to do the linking in a systematic manner, instead of just manually linking all over, you systematically tabulate all the implementation for a particular interface, then the linking table to structure part can be done automatically.
6. resourcemanagerment
compare to heap and stack, stack is used to put things of known length, heap is for things that are dynamic(how is heap implemented?) aftermain, heap allocation would still persist. What i did yersterday is to establish a global variable where the pointer is located, then I would use __attribute__((destructor))flag, which tell the compiler to exercute it after main. (gcc use this attribute flag, other compilers use #pragma startup or #pragma exit to indicate before or after main).
because of its dynamic nature,heap allocation would be more costly in terms of tiem.
the actual destructor in c++, defaut one, would be called automatically when exit the scope.

some feedback with respect to inspecting the code, I spent quite sometime trying to track the implementation of automatic calling of destructor in g++. gdb is obviously a good tool, the assembly view in particular but it doesn't show me where the source code is.
How to deepen my understanding of c++ with source code? is there more guidance on this effort? otherwise, it felt a bit waste of time.

7. remarks on mental state:
making steady progress like the way I do with cpp is a very gratifying thing. cpp has enough idiosyncracy to keep me occupied for quite sometime.
the most fear state, and in my mind, a waste of time is the following:

a) too macro: when faced with a complicated object, can't find a disecting point. This is the state where you ended up in circles and filled with fear and emotion but not making progress. for instance, trying to learn operating system in 20 days. I ended up just gloss over this topic.

b) too micro: you can dig into something infinitely. but there would be a point when things are just too micro to matter, where is that balance point?
that is why the best state is when you can see the picture from above but also the immediate next steps.

c) unfair market value: there is actually another thing that irritates me the most, that is when i realized that certain work of mine are valued unfairly. The real solution to this problem is two fold, one is try to ignore market valuation at the time being, when I am still training towards taht marketable skillset. The second would be trying to find a channel where the valuation might be favorable.
as of now, i am certain that cpp for numerical computation is a valuable skillset. To fulling mater cpp is gonna take sometime. there are also higher target as well, cpp implementation of machine learning for instance, which i do hope to accomplish at around this time next year.
in terms of valuation, i think what I am gonna do is to spread my potential employeer world wide.There is a way to market my experience into a win, and that should be something i do at the end of next year when i apply for phd program.

this also lead to the issue of subspace. Every subspace has its own univers, its rule of operation. what is true in one subspace is not necessarily true in the other. It is always harder to be out of sync with the current subspace. is there a softer approach to ensure one is not dragged down by the environment?

there is a balance, between hard-core skill and the rules to valuate those skill. what is the best road for that balance?Is it possible to cultivate expertise as an independent individual who depend on institution only when necessary?

d) can't think things through, ended up putting off fire all the time.I would love to have a deeper understanding of gcc compiler such that i can interact with it in a more efficient manner. 

e) not methotical: when you are exploring options, you want to be able to the entire picture relatively quickly, so you need to devote considerable amount of time to it. However, at this point, I should have my target locked, which is implementing machine learning mechanism on a piece of sillicon, be it GPU or other non-cpu structure. at this point, I should have a very clear path towards that target, and how to organize my time arount that goal.


Like every dynamically balanced system, the key component is a mechanism for counteracting the dominant force. for instance, there would be times when a overview is needed, then don't set your target to be in full command of that subject, that would only bring about frustration. When you are too deep in the woods, spending way too much time on the arcane details, remind yourself why you are doing this, and if there is more efficient way to accomplish your objective. When you are in a
dark place, can't see the road ahead, or seeing other's being valued unproportionally, remind yourself that you don't know all the possibilities and should focus on polishing a skill instead of squandering energy on things that are out of your control.

There is a mental state when I am extremely productive. Quietly following the lead to see the entire picture. My goal is to be there for as much time as possible, that call for selfmanagement techniques. I would summarize every technique comes my way as they happen.
the first and formost: look the other way. If a particular way of looking at things is not constructive, keep looking at things that way would only drag yourself into a quagmire. Look the other way, much like the mechanism to counteract the dominant force, such that a dynamic balance is obtainable.
