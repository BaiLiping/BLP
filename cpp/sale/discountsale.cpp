#include "discountsale.h"
DiscountSale::DiscountSale():Sale, discount(0){}
DiscountSale::DiscountSale(double the_price, double the discount):Sale(the_price),discount(the_discount){}
double DiscountSale:Bill() const{
    double fraction=discount/100;
    return (1-fraction)*price;
}

