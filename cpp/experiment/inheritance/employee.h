
#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;
class Employee{
    private:
        string name;
        string ssn;
        double net_pay;
    public:
        Employee();
        Employee(string n, string s,double p=0);
        ~Employee();
        string get_name() const{
            return name;
        };
        string get_ssn() const{
            return ssn; 
        };
        double get_net_pay() const {
            return net_pay;
        };
        void set_name(string new_name){
            name=new_name;
        };
        void set_ssn(string new_ssn){
            ssn=new_ssn;
        };
        void set_net_pay(double new_net_pay){
            net_pay=new_net_pay;
        };
        void print_check() const;
        
};


#endif
