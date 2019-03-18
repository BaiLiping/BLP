
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
    vector<int> initial={1,2,3,4,5};
    vector<int> second(initial.begin(),initial.begin()+3);
    vector<int> third(initial.begin()+3,initial.end());
    for(auto x:second) cout<<x;
    cout<<endl;
    for(auto x:third) cout<<x;
    cout<<endl;
    return 0;
}
