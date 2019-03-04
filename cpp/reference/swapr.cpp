#include <iostream>
using namespace std;

void swapr(int &, int &);
void swapp(int *, int *);
int main(){
    int first=1;
    int second=2;
    swapr(first, second);
    cout<<first<<" "<<second<<endl;
    swapp(&first, &second);
    cout<<first<<" "<<second<<endl;
    return 0;
}
void swapr(int & a, int & b){
    int temp;
    temp=a;
    a=b;
    b=temp;
}
void swapp(int * a, int * b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
