#include <queue>
#include <stack>
using namespace std;
#ifndef BST_H 
#define BST_H
template<class T>
struct BSTNode {
    BSTNode() {
        left = right = NULL;
    }
    BSTNode(const T& d, BSTNode<T> *l = NULL, BSTNode<T> *r = NULL) {
        data = d; left = l; right = r;
    }
    T data;
    BSTNode<T> *left, *right;
};


template<class T>
class BST {
public:
BST() {
root = NULL;
    cout<<"constructor has been activated"<<endl;
}

~BST() {
    cout<<"decontstructor has been activated"<<endl;
}

bool isEmpty() const {
    return root == NULL;
}

void insertTreeNode(BSTNode *, T);
void buildTree(vector<T> &);
//void printTree();

private:
BSTNode * root;
/*
void preorder() {
preorder(root);
}
void inorder() {
inorder(root);
}
void postorder() {
postorder(root);
}
T* search(const T& el) const {
return search(root,el);
}
void breadthFirst();
void iterativePreorder();
void iterativeInorder();
void iterativePostorder();
void MorrisInorder();
void insert(const T&);
void deleteByMerging(BSTNode<T>*&);
void findAndDeleteByMerging(const T&);
void deleteByCopying(BSTNode<T>*&);
void balance(T*,int,int);
protected:
BSTNode<T>* root;
void clear(BSTNode<T>*);
T* search(BSTNode<T>*, const T&) const;
void preorder(BSTNode<T>*);
void inorder(BSTNode<T>*);
void postorder(BSTNode<T>*);
//virtual void visit(BSTNode<T>* p) {
//cout << p->el << ' ';
//}*/

};
#endif
