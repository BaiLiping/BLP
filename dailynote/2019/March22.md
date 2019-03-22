1. c++11 and c++14 has addded the following new capacites and one should change the coding practice accordingly:
 typededuction, with auto
 using auto might be more beneficial compares to explicit declaration the type of variable, because of initialization. (there is a distinction between initialization and assignment) initilization means when that slot of memory is given to a certain variable, that  slot of memory is also filled with data that it should contain. 
 Uninitialized variable means the literal for that variable has been registered, but the actual allocation of memory and filling in the data would not happy until when that variable is assigned to a value. 
 assignment means there are two steps: 






