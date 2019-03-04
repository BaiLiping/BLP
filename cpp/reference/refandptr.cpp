#include <iostream>
#include <string>

using namespace std;

string st1("Hello");
string st2("World");
string & sr = st1;
string * sp = & st1;

int main(){
    cout<<sr<<endl;
    cout<<*sp<<endl;
    
    sr=st2;
    //the reference does not change, but the content changes.
    sp=&st2;
   
    cout<<sr<<endl;
    cout<<st1<<endl;

    return 0;

}
/*the main difference between ptr and ref. ptr can point to NULL and can change value during runtime, reference will always refer to the initialized address and will never refer to NULL*/
