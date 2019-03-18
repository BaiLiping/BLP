
#include<iostream>
#include "discount.h"
using namespace std;
double Discount::bill() const{
    double fraction = discount/100;
    return (1-fraction)*price;
}
