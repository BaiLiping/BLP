#include <iostream>
#include "stock.h"
using namespace std;
int main(){
    Stock stock1("FIRST", 1, 1.0);
    stock1.show();
    Stock stock2= Stock ("SECOND", 2, 2.0);
    stock2.show();

    return 0;
}
