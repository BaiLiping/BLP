
#include<iostream>
#include<cmath>
#include<string>
#include<vector>
#include<array>
#include<algorithm>
using namespace std;
template<typename T>
class Node{
    private:
    T data;
    Node<T> * left;
    Node<T> * right;
    public:
    void increase(T val=0){
        data+=val;
    }
    Node(T d=0,Node<T>* l=NULL,Node<T>* r=NULL): data(d),left(l),right(r){}
};

int main(){
    Node<int> node1;
    Node<int> node2(3);
    node1.increase(3);
    node2.increase();
    cout<<node1.data<<endl;
    cout<<node2.data<<endl;
    return 0;
}
