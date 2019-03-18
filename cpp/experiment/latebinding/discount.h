
#ifndef DISCOUNT_H
#define DISCOUNT_H
#include "sale.h"
class Discount:public Sale{
    protected:
        double discount;
    public:
        Discount(double p=0, double d=0):Sale(p),discount(d){
            cout<<"A Discount Object Has Been Created"<<endl;
        };
        ~Discount(){
            cout<<"A Discount Object has been Destroyed\n";
        };
        virtual double bill() const;

};


#endif
