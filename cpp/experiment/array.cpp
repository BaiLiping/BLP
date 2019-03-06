#include <array>
#include <iostream>
using namespace std;
int climbStairs(int);
unsigned i=0;
int arr[200]={0};
//arr[1]=1;
//arr[2]=2;

int main(){
//static int arr[200]={0};
arr[1]=1;
arr[2]=2;
//cout<<"enter a number: \n";   
//cin>>i;
int n=10;
//for (int k=0;k<=i;k++){
cout<<climbStairs(n)<<endl;
//}
cout<<endl;
}
    
    int climbStairs(int n) {
        if (arr[n]!=0||n==0) return arr[n]; 
        
        else{
            if (n<0) std::exit(1);
            i=climbStairs(n-2)+climbStairs(n-1);
            arr[n]=i;
            return i;
        }       
    }
