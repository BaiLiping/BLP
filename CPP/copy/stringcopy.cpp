
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

int main(){
    int i=3;
    int *j=new int(4);
    string s1="HelloWorld";
    string s2=s1;
    string s3=move(s1);
    string s4(s2);
    s2[2]='K';
    s4[2]='R';
    s3[2]='P';
    cout<<&i<<endl;
    cout<<j<<endl;
    cout<<s1<<endl;
    cout<<s2<<endl;
    cout<<s3<<endl;
    cout<<s4<<endl;
    cout<<&s1<<endl;
    cout<<&s2<<endl;
    return 0;

}
