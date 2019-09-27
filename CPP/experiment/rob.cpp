#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int rob(vector<int> &);

int main(){
   // vector<int> v={183,219,57,193,94,233,202,154,65,240,97,234,100,249,186,66,90,238,168,128,177,235,50,81,185,165,217,207,88,80,112,78,135,62,228,247,211};
    vector<int> v={9,1,2,10};
    cout<<rob(v)<<endl;
    return 0;
}


/*int rob(vector<int>& nums) {
    vector<int>::iterator ptr=nums.begin();
    if (nums.size()==0) return 0;
    if (nums.size()==1) return nums[0];
    if (nums.size()==2) return max(nums[0],nums[1]);
    //if (nums.size()==3) return max(*(ptr+1),(*ptr)+(*(ptr+2)));
        
    vector<int> result;
    int arr[200]={0}; 
    vector<int> first(ptr+2,nums.end());
    arr[0] =rob(first)+(*ptr);
    int j=0;
        
    for(ptr++;ptr!=nums.end()-1;ptr++){
         vector<int> first_half(nums.begin(),ptr-1);
         vector<int> second_half(ptr+2,nums.end());
         first_half.insert(first_half.end(),second_half.begin(),second_half.end());
         j++;
         arr[j]=rob(first_half)+(*ptr);
        }
        
    vector<int> last(nums.begin(),ptr-1);
    j++;
    arr[j]=rob(last);
    auto max_result=max_element(arr,arr+j+1);
    return *max_result;    
}*/
int rob(vector<int> &num) {
         if (num.empty()) return 0;
         if (num.size()==1) return num[0];
         int p[num.size()];
         p[0] = num[0];
         p[1] = max(num[0], num[1]);
 
         for (int i = 2;i < num.size();i++)
             p[i] = max(p[i-2] + num[i], p[i-1]);
         return p[num.size()-1];
     }

