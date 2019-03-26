comapre traditional cpp to cpp11 and above:
1. range specifier
for(auto i=v.begin();i!=v.end();++i) can be written as for(auto x:v)
2. rvalue, basically, rightvalue is to tell compiler that after you are done with the content of this object, you can destroy it. It is very much marked for destruction.
3. perfect forwarding:
container.emplacement("string literal") use perfect forwarding therefore, as efficient as it can be.
4. auto, and decltype(mostly used in generic programming) this type deduction facility
5. bracket initialization. There are various ways of initializing an object and sometimes it can get confusion, you don't quite know which one is initialization and which one is assignment. which one involve contructor, destructor etc. bracket initialization syntax is designed as some sort of universal syntax, such that you can initialize anything with bracket, with the caveat of initliazer_list, which I did not get into.
6. move synmatic: the compiler generated default functions are the following:
constructor:
destructor
copy constructor(shallow copy)
copy assignment operator
now there are two more:
move constructor
move assignment operator

7. lambda expression and function class. when you define a class, if you overload the parathesis operator, then you get yourself a functor(function operator, i guess). lambda expression is a way to simplify that definition into its bare bone. It is particularly useful for functors that's gonna be called once only, such as inside of algorithm.
[] doesn't catch
[=] catch by value
[&] catch by reference

9. the operations of standard committee, working paper, proposal, currently we are on c++20, a major change there would be the concept proposal which is already available on gcc and clang.apparently there are three major compiler vendors, gcc, clang and microsoft visual studio.

10. target for today is to practice on heap.
