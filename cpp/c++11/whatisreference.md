In a declaration, the unary suffic & means "reference to" A reference is similar to a pointer, except that you don't have to dereference it to get its value. (question, does that mean fundamentally speaking, reference is a pointer? or just an alias to an existing object?) A reference can't point to NULL and must be initialized. It can't change object it refers to after initialization.
Reference are Particularly useful for passing parameter to function.

the design of reference is a syntactical one. ALso, checking for nullptr can be non-trivia, and reference is a mechanism against that. 

The committee does not specify or require implementation details so long as the behaviour is compliant to the guidance.

Often time, reference is implemented with const *, and automatically dereference itself everytime it is refreeed to.

the idea of having more than one kind of reference is to support different use of objects
1. non-const lvalue reference refers to an object, to which the user of the reference can write.
2. a const lvalue reference refers to a constant, whihc is immutable from the client perspective.
3. an rvalue reference refers to a temporary object, which the user of the reference can modify, assuming thath the object will never be used again.

the distinction here is wheather the object it refers to is temprary, becuase if it is, we can sometimes turn an expensive copy opeartion into a cheap move operation. 

basically one can think of rvalue reference as mark for destruction.

