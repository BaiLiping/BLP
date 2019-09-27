#ifndef STOCK_H
#define STOCK_H

#include <string>
using namespace std;
class Stock{
    public:
        Stock();
        Stock(const string & co, long n=0, double pr=0.0);
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
    private:
        string company;
        long shares;
        double share_val;
        double total_val;
        void set_total(){total_val=shares*share_val;};
        const Stock & topval(const Stock & s) const;
};
#endif
