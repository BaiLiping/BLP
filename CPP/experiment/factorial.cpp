
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

    template<uint64_t n>
        struct Factorial{
            enum{
                value=n*Factorial<n-1>::value
            };
        };
    template<>
        struct Factorial<0>{
            enum{
                value=1
            };
        };

int main(){
    cout<<Factorial<50>::value<<endl;
    cout<<Factorial<60>::value<<endl;
    return 0;
}
