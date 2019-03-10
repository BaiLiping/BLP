
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
template<int N>
struct blpabs{
    //static_assert(N!=INT_MIN);
    static const int value=(N<0)?-N:N;
};

int main(){
    int const n=-18;
   cout<<blpabs<n>::value<<endl;
    return 0;
}
