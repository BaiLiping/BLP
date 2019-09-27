#include <iostream>
using namespace std;
int climbStairs(int);

int main(){
    int n;
    
    cout<<"enter a number: \n";
    cin>>n;

    for(int i=0;i<n;i++){
        cout<<climbStairs(i)<<endl;
        i++;
    }
    return 0;
}
 unsigned j=0;
 int climbStairs(int n) {
     if (n<0) std::exit(1);
     if (n==0) return 0;
     if (n==1) return 1;
     if (n==2) return 2;
     j=climbStairs(n-2)+climbStairs(n-1);
     return j;        
}
