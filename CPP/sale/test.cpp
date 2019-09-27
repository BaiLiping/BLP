#include <iostream>
#include "sale.h"
#include "discountsale.h"
using namespace std;
int main(){
    Sale sample(10.00);
    DiscountSale discount(11.00,10);
    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(2);
    if (discount<sample){
        count<<"Discounted item is cheaper.\n";
        count<<"Saving is $"<<sample.savings(discount)<<endl;
    }
    else
        cout<<"Discounted item is not cheaper.\n";
    return 0;
}
