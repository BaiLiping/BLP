#include <iostream>
#include <vector>
using namespace std;
int main(){
    char a='a';
    char A='A';
    vector<int> v(300,1);
    //std::vector<int>::iterator ptr=v.begin();
    
    for(int i=0;i<v.size();i++){
        v[i]=i;
    }
    cout<<a<<" "<<A<<endl;
    cout<<v['&']<<" "<<v['@']<<endl;
    return 0;
}
