#include <iostream>
//#include <cintstd>
#include <vector>
using namespace std;


int main()
{
  vector<uint64_t> lookuptable;
  std::vector<uint64_t>::iterator p;
  p=lookuptable.begin();
  *p=1;
  *(p+1)=2;
  *(p+2)=3;
  cout<<*(p+2)<<endl;
  return 0;
}


