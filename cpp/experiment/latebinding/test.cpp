
#include<iostream>
#include "sale.h"
#include "discount.h"
using namespace std;

int main(){
    Sale s1(7);
    Discount d1(5,15);
    cout<<s1.bill()<<endl;
    cout<<d1.bill()<<endl;
    
    if (d1<s1){
        cout<<"Discount is cheaper.\n";
        cout<<"Saving is $"<<s1.savings(d1)<<endl;
    }
    else
        cout<<"Discount item is more expensive.\n";
    return 0;
}
