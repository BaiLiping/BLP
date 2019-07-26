#include<iostream>
#include<vector>
using namespace std;

int main(){
vector<int> v= {0,1,2,3,4};
for (auto i: v){
cout<<i<<endl;
}
cout<<v[2]<<endl;
for (auto & i: v) {
cout<<i<<endl;
}
cout<<v[2]<<endl;
}
