#include <iostream>
#include "bst.h"
using namespace std;

template<class T>

/*T* BST<T>::search(BSTNode<T>* p, const T& el) const {
while (p != 0)
if (el == p->el)
return &p->el;
else if (el < p->el)
p = p->left;
else p = p->right;
return 0;
}*/

template<class T>
void BST<T>::insertTreeNode(BSTNode * parent,T element){
    if (isEmpty()) root=new BSTNode(element);
    else{
        newnode=new BSTNode(element);
        if (element<parent->data)
            {if (element<parent->left->data)
                insertTreeNode(parent->left->element);
            else{
                newnode->left=parent->left;
                parent->left=newnode;
            }
        }
        else{
            if(element>parent->right->data)
                insertTreeNode(parent->right,element);
            else{
                newnode->right=parent->right;
                parent->right=newnode;
            }
    }
}
template<class T>
void BST<T>::buildTree(vector<T> &input_data){
    inputdata[0]=min(input_data[0],input_data[1]);
    inputdata[1]=min(input_data[1],input_data[2]);
    root=BSTNode(input_data[1],BSTNode(input_data[0]),BSTNode(input_data[2]));
    for(int i=3;i<input_data.size();++i){
        insertTreeNode(input_data[i]);
    }
}

/*template<class T>
void BST<T>::printTree(){

}

*/



/*

template<class T>
void BST<T>::breadthFirst() {
Queue<BSTNode<T>*> queue;
BSTNode<T> *p = root;
if (p != 0) {
queue.enqueue(p);
while (!queue.empty()) {
p = queue.dequeue();
visit(p);
if (p->left != 0)
queue.enqueue(p->left);
if (p->right != 0)
queue.enqueue(p->right);
}
}
}
template<class T>
void BST<T>::inorder(BSTNode<T> *p) {
if (p != 0) {
inorder(p->left);
visit(p);
inorder(p->right);
}
}
template<class T>
void BST<T>::preorder(BSTNode<T> *p) {
if (p != 0) {
visit(p);
preorder(p->left);
preorder(p->right);
}
}
template<class T>
void BST<T>::postorder(BSTNode<T>* p) {
if (p != 0) {
postorder(p->left);
postorder(p->right);
visit(p);
}
}
template<class T>
void BST<T>::iterativePreorder() {
Stack<BSTNode<T>*> travStack;
BSTNode<T> *p = root;
if (p != 0) {
travStack.push(p);
while (!travStack.empty()) {
p = travStack.pop();
visit(p);
if (p->right != 0)
travStack.push(p->right);
if (p->left != 0)
travStack.push(p->left);
}
}
}
template<class T>
void BST<T>::iterativePostorder() {
Stack<BSTNode<T>*> travStack;
BSTNode<T>* p = root, *q = root;
while (p != 0) {
for ( ; p->left != 0; p = p->left)
travStack.push(p);
while (p->right == 0 || p->right == q) {
visit(p);
q = p;
if (travStack.empty())
return;
p = travStack.pop();
}
travStack.push(p);
p = p->right;
}
}
template<class T>
void BST<T>::iterativeInorder() {
Stack<BSTNode<T>*> travStack;
BSTNode<T> *p = root;
while (p != 0) {
while (p != 0) {
if (p->right)
travStack.push(p->right); // to the left;
travStack.push(p);
p = p->left;
}
p = travStack.pop();
while (!travStack.empty() && p->right == 0) { // visit it
visit(p);
p = travStack.pop(); // child;
}
visit(p);
if (!travStack.empty()) // a right child (if any);
p = travStack.pop();
else p = 0;
}
}
template<class T>
void BST<T>::MorrisInorder() {
BSTNode<T> *p = root, *tmp;
while (p != 0)
if (p->left == 0) {
visit(p);
p = p->right;
}
else {
tmp = p->left;
while (tmp->right != 0 &&
tmp->right != p)
tmp = tmp->right;
if (tmp->right == 0) {
tmp->right = p;
p = p->left;
}
else {
visit(p);
tmp->right = 0;
p = p->right;
}
}
}

template<class T>
void BST<T>::insert(const T& el) {
BSTNode<T> *p = root, *prev = 0;
while (p != 0) { // find a place for inserting new node;
prev = p;
if (el < p->el)
p = p->left;
else p = p->right;
}
if (root == 0)
root = new BSTNode<T>(el);
else if (el < prev->el)
prev->left
= new BSTNode<T>(el);
else prev->right = new BSTNode<T>(el);
}

//template<class T>
//void threadedtree<T>::insert(const T& el) {
//ThreadedNode<T> *p, *prev = 0, *newNode;
//newNode = new ThreadedNode<T>(el);
//if (root == 0) {
//root = newNode;
//return;
//}
//p = root;
//while (p != 0) {
//prev = p;
//if (p->el > el)
//p = p->left;
//else if (p->successor == 0) // go to the right node only if it
//p = p->right; // is a descendant, not a successor;
//else break;
//}
//if (prev->el > el) {
//prev->left = newNode;
//newNode->successor = 1;
//newNode->right = prev;
//}
//else if (prev->successor == 1) {// if the parent of newNode
//newNode->successor = 1;
//prev->successor = 0;
//newNode->right = prev->right; // newNode’s successor,
//prev->right = newNode;
//}
//else prev->right = newNode;
//}
//
template<class T>
void BST<T>::deleteByMerging(BSTNode<T>*& node) {
BSTNode<T> *tmp = node;
if (node != 0) {
if (!node->right)
node = node->left;
else if (node->left == 0)
node = node->right;
else {
tmp = node->left;
while (tmp->right != 0)// 2. and then right as far as
tmp = tmp->right;
tmp->right=node->right;
tmp = node;
node = node->left;
}
delete tmp;
}
}

template<class T>
void BST<T>::findAndDeleteByMerging(const T& el) {
BSTNode<T> *node = root, *prev = 0;
while (node != 0) {
if (node->el == el)
break;
prev = node;
if (el < node->el)
node = node->left;
else node = node->right;
}
if (node != 0 && node->el == el)
if (node == root)
deleteByMerging(root);
else if (prev->left == node)
deleteByMerging(prev->left);
else deleteByMerging(prev->right);
else if (root != 0)
cout << "element" << el << "is not in the tree\n";
else cout << "the tree is empty\n";
}

template<class T>
void BST<T>::deleteByCopying(BSTNode<T>*& node) {
BSTNode<T> *previous, *tmp = node;
if (node->right == 0)
node = node->left;
else if (node->left == 0)
node = node->right;
else {
tmp = node->left;
previous = node;
while (tmp->right != 0) {
previous = tmp;
tmp = tmp->right;
}
node->el = tmp->el;
if (previous == node)
previous ->left = tmp->left;
else previous ->right = tmp->left; // 4.
}
delete tmp;
}

*/

