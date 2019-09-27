
#include<iostream>
using namespace std;
class DayOfYear{
    public:
        friend bool equal(DayOfYear, DayOfYear);
        DayOfYear(int m, int d):month(m),day(d){
            cout<<"a date has been created"<<endl;
        };
        int get_month() const{
            return month;
        };
        int get_day() const{
            return day;
        };
        void print(){
            cout<<"Month = "<<month<< " , day = "<<day<<endl;
        }
    private:
        int month;
        int day;

};//end of class DayofYear
//bool equal(DayOfYear date1, DayOfYear date2);

int main(){
    DayOfYear birthday(3,21);
    DayOfYear randomday(5,21);
    if(equal(birthday, randomday)) birthday.print();
    randomday.print();
    return 0;
}//end of main

/*bool equal(DayOfYear date1, DayOfYear date2){
    return ((date1.get_month()==date2.get_month())&&(date1.get_day()==date2.get_day()));
}*/

//notice when defining a function, it is the same as would a normal function
bool euqal(DayOfYear date1, DayOfYear date2){
    return ((date1.month==date2.month)&&(date1.day==date1.day));
}

