#include<iostream>
#include<vector>
#include <string>
#include <bits/stdc++.h> 
using namespace std;
int main(){
    vector<int> v{ 1, 5, 8, 9, 6, 7, 3, 4, 2, 0 }; 
    string s="";
    s.push_back('a');
    s.push_back('b');
    s.append("cdefg");

    for (auto x:s)
        cout<<x<<" ";
    cout<<s.size()<<endl;

    std::sort(v.begin(), v.end()); 
  
    cout << "Sorted \n"; 
    for (auto x : v) 
        cout << x << " ";
    cout<<endl;
  
    return 0;
}
