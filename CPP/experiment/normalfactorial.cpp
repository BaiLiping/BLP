
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
uint64_t factorial(int n);

int main(){
    cout<<factorial(50)<<endl;
    return 0;
}

uint64_t factorial(int n){
    if(n==0) return 1;
    else return n*factorial(n-1);
}
