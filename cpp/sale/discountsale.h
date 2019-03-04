#ifndef DISCOUNTSALE_H
#define DISCOUNTSALE_H
#include "sale.h"
calss DiscountSale: public Sale{
    public:
        DiscountSale();
        DiscountSale(double the_price, double the_discount);
        virtual double bill() const;
    protected:
        double discount;
};
#endif
