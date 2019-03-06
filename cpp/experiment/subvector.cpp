#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int main(){
    vector<int> s={1,2,3,4,5,6};
    vector<int>::iterator ptr=s.begin();
    //to include the last element, the subvector need to go to .end()
    //the syntax is p(vectorbegin, vector end);
    vector<int> p1(ptr,ptr+2);
    vector<int> p2(ptr+4,s.end());
    p2.insert(p1.end(),p2.begin(),p2.end());
    vector<int>::iterator pptr=p2.begin();
    cout<<*pptr<<*(pptr+p.size()-1)<<endl;
    //max_element(beginpotr, endptr) function returns the ptr to max element;
    auto max_e = std::max_element(s.begin(), s.end());
    cout<<*max_e<<endl;
    return 0;
}
