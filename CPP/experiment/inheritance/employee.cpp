
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<string>
#include"employee.h"
using namespace std;
Employee::Employee():name(""),ssn(""),net_pay(0){
    cout<<"A Employee Record Has been Established"<<endl;
}
Employee::Employee(string n, string s, double p=0):name(n), ssn(s),net_pay(p){
    cout<<n<<"'s Record has been Established"<<endl;
}
Employee::~Employee(){
    cout<<"Employee Record has been Destroyed"<<endl;
}
void Employee::print_check() const{
    cout<<"\nERROR:print_check FUNCTION CALLED FOR AN\n"<<"UNDIFFERENTIATED EMPLOYEE.ABORTING THE PROGRAMME\n";
    exit(1);
}
