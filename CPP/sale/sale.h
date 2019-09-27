#ifndef SALE_H
#define SALE_H
#include <iostream>
using namespace std;
class Sale{
    public:
        sale();
        Sale(double the_price);
        virtual double bill() const;
        double saving(const Sale & other) const;
    protected:
        double price;
};
bool operator < (const Sale & first, const Sale & second);
#endif
