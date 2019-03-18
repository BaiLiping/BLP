
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<string>
#include"hourly.h"
using namespace std;

Hourly::Hourly():Employee(),wage_rate(0),hours(0){
    cout<<"A Record for Hourly Employee has been Established "<<endl;
}
Hourly::Hourly(string n, string s, double new_wage_rate, double new_hours):Employee(n, s), wage_rate(new_wage_rate),hours(new_hours){
    cout<<n<<"'s Hourly Employee Record has been Established\n";
}
Hourly::~Hourly(){
    cout<<"A Hourly Employee Record has been Destroyed\n";
}
void Hourly::print_check(){
    set_net_pay(hours*wage_rate);
    cout<<"\n___________________________________\n";
    cout<<"Pay to the order of "<<get_name()<<endl;
    cout<<"The sum of "<<get_net_pay()<<" Dollars\n";
    cout<<"_____________________________________\n";
    cout<<"Employee Number: "<<get_ssn()<<endl;
    cout<<"Hourly Employee. \n Hours Workded: "<<hours<<" Rate: "<<wage_rate<<" Pay: "<<get_net_pay()<<endl;
    cout<<"______________________________________ \n";
}

