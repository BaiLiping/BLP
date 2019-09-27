
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;

class Node{
    int value;
    Node * left;
    Node * right;
    Node(int val,Node * l=NULL, Node * r=NULL):value(val),left(l),right(l){}
    int increaseval(){
        ++value;
    }
    int getval(){
        return value;
    }
};


int main(){
    Node newnode(3);
    newnode.increaseval();

    return 0;
}
