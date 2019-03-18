
#include<iostream>
#include<cassert>
#include<cstdlib>
#include"sale.h"
using namespace std;

double Sale::bill() const{
    return price;
}
double Sale::savings(const Sale & other) const{
    return (bill()-other.bill());
}
bool operator<(const Sale & first, const Sale & second){
    return (first.bill()<second.bill());
}
