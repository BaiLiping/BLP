
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
#include "1.h"
using namespace std;
//define it in update.cpp, declair it at 1.h, the globle variable;
//static int globle=10; declare here would not work

int main(){
    //globle=10;
    cout<<globle<<endl;
    cout<<::globle<<endl;
    update();
    globle++;
    cout<<globle<<endl;
    cout<<::globle<<endl;
    return 0;
}
