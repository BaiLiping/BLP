
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

// defining the global variable
//int a=1;
static int a=3;
int main()
{
    //local variable
    //int a=50;
    cout<<"local a: "<<a<<" Global a: "<<::a<<endl;
    
    // Re-defining global variable by using ::
    ::a=2;
    cout<<"local a: "<<a<<" Global a: "<<::a<<endl;
    return 0;
}
