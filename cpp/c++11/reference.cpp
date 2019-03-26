
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

int main(){
    //the raison d'tre for reference is the facilitate passing address to function with the same syntax as does regular object, such that unnecessary confusion can be minimized. the desired behaviour of reference are the following:
    //1. passing address
    //2. no considerable amount of overhead.
    //3. same syntax, without the dereferencing stuff
    //4. no Null reference
    //5. can not change after initialization
    //the committee does not specify implementation for the reference so long as the behaviour is compliant
    //most often, reference is implemented in terms of const_ptr;
    //a good way to think about reference really is alias of an object.
    int a=5;
    int & b =a;
    const int * c =&a;
    cout<<&a<<endl;
    cout<<&b<<endl;//although reference is implemented with const * but it is also required to have the same syntax as an object. therefore, to refer to its address, you still need to use the & sigh.
    cout<<c<<endl;
    
    
    
    return 0;
}
