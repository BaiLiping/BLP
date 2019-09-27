
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<cstdint>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

int main(){
    //size_t is alias for unsigned integer type, sizeof is 8, uint32_t
    size_t i=34;
    uint64_t j=132141523423412312;
    cout<<sizeof(i)<<" "<<sizeof(j)<<endl;    
    return 0;
}
