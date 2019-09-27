#include <iostream>
#include "stock.h"
using namespace std;
Stock::Stock(){
    cout<<"Decault Constructor Called\n";
    company="no name";
    shares=0;
    share_val=0.0;
    total_val=0.0;
}
Stock::Stock(const string & co, long n, double p){
    cout<<"Defined Constructor Called\n";
    company=co;
    shares=n;
    share_val=p;
    set_total();
}
Stock::~Stock(){
    cout<<"Deconstructor Called\n";
}
void Stock::buy(long num, double price){
    shares+=num;
    share_val=price;
    set_total();
}
void Stock::sell(long num, double price){
    shares-=num;
    share_val=price;
    set_total();
}
void Stock::update(double price){
    share_val=price;
    set_total();
}
void Stock::show(){
    cout<<"Company: "<<company<<endl;
    cout<<"Shares: "<<shares<<endl;
    cout.precision(2);
    cout<<"Price: "<<share_val<<endl;
    cout<<"Total Worth: "<<total_val<<endl;
}
const STock & Stock::topval(const STock & s) const {
    if(s.total_val>total_val){
        return s;
    }
    else
        return *this;
}

