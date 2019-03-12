
#ifndef BST_H
#define BST_H
#include <iostream>
#include <string>
#include<vector>
using namespace std;

template<typename T>
class Node{
    public:
    T data;
    int level;
    Node<T> * parent;
    Node<T> * leftChild;
    Node<T> * rightChild;
    Node<T>(T val=0,int le=0, Node<T> *p=NULL, Node<T> * l=NULL,Node<T> * r=NULL):data(val),level(le),parent(p),leftChild(l),rightChild(r){};
};

template<typename T>
class BST{
    private:
        void set_level();
        int get_level(Node<T>*);
        void in_order_traverse(Node<T>*);
        void insert(T);
        Node<T> * root;
        void left_rotate();
        void right_rotate();
        bool isBalanced();
        void balance_tree();
        void layout(Node<T>*,vector<vector<string>>&,int,int,int);
        void level_order_travesal(Node<T> *,vector<vector<T>> &,int);
    public:
        BST<T>();
        ~BST<T>();
        T min_elem();
        T max_elem();
        void build_tree(vector<T> &);
        void print();
        void matrix_print();
        void level_print();
};

template class BST<int>;
template class BST<double>;
template class Node<int>;
template class Node<double>;
#endif
