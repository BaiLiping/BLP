
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<cmath>
#include<string>
#include"salary.h"
using namespace std;

Salary::Salary():Employee(),salary(0){
    cout<<"A Record for Salaried Employee has been Established"<<endl;
}
Salary::Salary(string n, string s, double sa):Employee(n,s),salary(sa){
    cout<<n<<"'s Salaried Employee Record has been Established\n";
}
Salary::~Salary(){
    cout<<"Salaried Employee Record has been Destroyed"<<endl;
}
void Salary::print_check(){
    set_net_pay(salary);
    cout<<get_name()<<endl;
    cout<<get_net_pay()<<" Dolloars\n";
}
//void Salary::print_check(){
  //  set_net_pay(salary);
   // cout<<get_name()<<endl;
//}
