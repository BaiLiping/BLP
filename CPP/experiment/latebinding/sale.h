
#ifndef SALE_H
#define SALE_H
#include <iostream>
using namespace std;
class Sale{
    protected:
        double price;
    public:
        Sale(double p=0):price(p){
            cout<<"A Sales Object has been Created\n";
        };
        ~Sale(){
            cout<<"A Sales Object has been Destroyed\n";
        }
        virtual double bill() const;
        double savings(const Sale &) const;
};
bool operator <(const Sale&first, const Sale& second);


#endif
