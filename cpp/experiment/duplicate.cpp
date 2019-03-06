#include <iostream>
#include <vector>
using namespace std;
int removeDuplicates(vector<int > &);

int main(){
    vector<int> v ={1,1};
    cout<<removeDuplicates(v)<<endl;
   // std::vector<int>::iterator ptr=v.begin();
   // v.erase(ptr);
   // cout<<*ptr<<endl;
    return 0;
}

int removeDuplicates(vector<int>& nums) {
    
    for( std::vector<int>::iterator ptr = nums.begin();ptr!=nums.end();){
        std::vector<int>::iterator running = ptr+1;
        while(running!=nums.end()){
            if ((*running)==(*ptr)) nums.erase(running);
            else running++;
        }
        ptr++;
    }
    return nums.size();
    }
