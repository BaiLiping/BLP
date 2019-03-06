#include <string>
#include <iostream>
using namespace std;

bool isValid(string);

int main(){
    //string s;
    //cout<<"enter string: \n";
    //cin>>s;
    string s="([)]";
    cout<<isValid(s)<<endl;
    return 0;
}

bool isValid(string s){
   if(s.size()%2==1) return false;
   string::iterator head = s.begin();
increment:
   while (head!=s.end()){
       string::iterator running=head+1;
       while(running!=s.end()){
           if((*running)==((*head)+1)||(*running)==((*head)+2)) {
               s.erase(head);
               s.erase(running);
               goto increment;
           }
           running++;
       }
       head++;
   }    
   return (*head==*(s.end()));
}
