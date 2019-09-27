#include <iostream>
#include <string>
#include <bits/stdc++.h> 
using namespace std;

//static int fast_io = []() { 
//    std::ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    return 0;
//}();

int lengthOfLongestSubstring(string);

int main(){
    string s="abcdababesacdea";
    cout<<lengthOfLongestSubstring(s)<<endl;
    return 0;
}



int lengthOfLongstSubstring(string s) {
        int max_size = 0;
        int left=-1;
        vector<int> last_index(128,-1);
        for(int i = 0,len = s.size();i < len; ++i){
            left = max(left,last_index[s[i]]);
            last_index[s[i]] = i;
            max_size=max(max_size, i-left);
        }
        return max_size;
    }

