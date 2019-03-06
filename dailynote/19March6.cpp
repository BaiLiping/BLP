
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

int main(){
    string s1="HelloWorld";
    vector<int> v1={1,2,3,4,5,6,7,8,9,0};
    vector<int>::iterator ptr=v1.begin();
    vector<int> v2(ptr+2,ptr+5);//the lastone won't be included as it would become v2.end();
    v1.insert(ptr+6,v2.begin(),v2.end());
    for(int i=0;i<v1.size();i++)
        cout<<v1[i];
    cout<<endl;
    auto max_ptr=max_element(v1.begin(),v1.end());
    cout<<*max_ptr<<endl;
    return 0;
}
