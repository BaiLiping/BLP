
#ifndef SALARY_H
#define SALARY_H
#include <string>
#include "employee.h"
using namespace std;

class Salary:public Employee{
    private:
        double salary;
    public:
        Salary();
        Salary(string,string, double);
        ~Salary();
        void set_salary(double newsalary){
            salary=newsalary;
        };
        double get_salary() const{
            return salary;
        };
        void print_check();
};
#endif
