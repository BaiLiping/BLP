1. preprocessor can declare things and initialize things, but more operation need to be put inside the main loop instead of the preprocessor portion of the code.
2. for(before for loop;end condition; at the end of the for loop)
eg: 
for(int i=0;int k=10;i<k;v++)
    doing certain things
is equivolent to:

int i=0;
int k=10;
while(i<k){
doing certain things;
v++
}

3. (condition)?(if true):(if false)
eg: x>y?z=x:z=y;

4 should do more iteration vs greedy algorithm.greedy algorithm seems to be saying that iteration can be done in linear time, if the constrain restricted things to that extend.

the condition for greedy algorithm to hold:
every step there is a max.


