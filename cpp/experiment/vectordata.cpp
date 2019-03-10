
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

int main(){
    vector<int> v={1,2,3,4,5};
    //data returns the actual pointer the underlying array uses to construct the vector container
    //it differ to iterator in subtal ways, since this is the actual pointer.
    auto p=v.data();
    cout<<p<<endl;
    return 0;
}
