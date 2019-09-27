
#ifndef HOURLY_H
#define HOURLY_H

#include <string>
#include "employee.h"
using namespace std;

class Hourly: public Employee{
    private:
        double wage_rate;
        double hours;
    public:
        Hourly();
        Hourly(string, string, double, double);
        ~Hourly();
        void set_rate(double new_wage_rate){
            wage_rate=new_wage_rate;
        };
        void set_hours(double hours_worked){
            hours=hours_worked;
        };
        double get_rate() const{
            return wage_rate;
        };
        double get_hours() const{
            return hours;
        };
        void print_check();
};

#endif
