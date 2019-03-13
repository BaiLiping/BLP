
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<queue>
#include<array>
#include<algorithm>
using namespace std;
struct Node{
    int data;
    struct Node * next;
    Node(int val):data(val),next(NULL){}
};

int main(){
    queue<Node> q1;
    Node node1(1);
    q1.emplace(node1);
    q1.emplace(node2(2));
    //q1.push(3);
    
    cout<<q1.front()->data<<endl;
    q1.pop();
    cout<<q1.front()->data<<endl; 
    q1.pop(); 
    cout<<q1.front()->data<<endl;
     return 0;
}
