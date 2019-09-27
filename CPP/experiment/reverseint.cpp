#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int reverse(int);

int main(){
    int x=901;
    cout<<reverse(x)<<endl;
    return 0;
}

  int reverse(int x) {
     vector<int> result;
     while(x%10==0){
         x=x/10;
     }
     int y=x%10;
     int z=0;
     while(x!=y){  
         result.push_back(y);
         x=(x-y)/10;
         y=x%10;
      }
     result.push_back(y);
      for(int i=0;i<result.size();i++){
          z+=result[result.size()-i-1]*pow(10,i);
      }    
        return x>0?z:(-1)*z;
    }
