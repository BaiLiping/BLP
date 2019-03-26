
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<algorithm>
#include <string>
#include <vector>
using namespace std;

template<class K, class V>
class blpMap{
    public:
    V& operator[](const K& v);//return the value corresponding to the key v
    pair<K,V> * begin(){return &elem[0];}
    pair<K,V> * end() {return &elem[0]+elem.size();}
    private:
    vector<pair<K,V>>elem;
};


int main(){
    blpMap<string, int> buf;
    for(string s;cin>>s;) ++buf[s];
    for (const auto & x: buf)
        cout<<x.first<<": "<<x.second<<endl;
    return 0;
}

template<class K, class V>
V & blpMap<K,V>::operator[](const K & k){
    for (auto & x:elem)
        if (k==x.first)
            return x.second;
    elem.push_back({k,V{}});
    return elem.back().second;
}
