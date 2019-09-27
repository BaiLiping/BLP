#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int>&);
int main(){
vector<int> v={2,9};
plusOne(v);
return 0;
}



vector<int> temp={};
    vector<int> plusOne(vector<int>& digits) {
        std::vector<int>::iterator tail = digits.end()-1;
        std::vector<int>::iterator head=digits.begin();
        if (*tail==9) {
            while(tail!=head){
                digits.pop_back();
                temp=plusOne(digits);
                temp.push_back(0);
                digits=temp;
                return digits; 
            }
            *tail=1;
digits.push_back(0);
                        
        }
        else  (*tail)++;
        return digits;
    }
