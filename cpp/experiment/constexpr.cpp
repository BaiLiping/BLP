
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

int main(){
    constexpr int a=10;
    constexpr int b=1;
    static_assert (a<b,"a have to be smaller than b");
    return 0;
}
