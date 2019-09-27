
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
#include<cassert>
#include<cstdlib>
using namespace std;

int main(int argc,char * argv[]){
//passing argument through main, eg./program arg1 arg2 
//argc=3
//argv[0]=./program
//argv[1]=arg1
//argv[2]=arg2
//the format is main(int argc, char * argv[])
//therefore the argv[1] is a char * to arg1
//to convert char to int, there are two ways, one is *argv[1]-'0'
//another is *argv[1]-48, as in ascii representation, digits are 48 higher than that of numbers
//assert(if not meet the condition)
//if(false) aboard program
//can only continue the program if the condition is met;
   assert(argc>1);
   int i=*argv[1]-48;
   assert(i<3);
   cout<<i<<endl;


    return 0;
}
