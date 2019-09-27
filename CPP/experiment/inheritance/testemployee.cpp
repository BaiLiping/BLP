
#include<iostream>
#include<cassert>
#include<cstdlib>
#include<string>
#include "employee.h"
#include"hourly.h"
using namespace std;

int main(){
    //Employee e1;
    //Employee e2("Alex","12345");
    Hourly h1;
    Hourly h2("Bob","4567",4.5,10);
    h1.set_name("Alex");
    h1.set_ssn("123");
    h1.set_rate(3.2);
    h1.set_hours(8);
    h1.print_check();
    h2.print_check();
    //e1.print_check();
    //e2.print_check();
    return 0;
}
