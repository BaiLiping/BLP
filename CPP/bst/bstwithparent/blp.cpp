#include<iostream>
#include<string>
#include<cmath>
#include<vector>
#include<algorithm>
#include<blp.hpp>
using namespace std;
template<typename T>
BST<T>::BST():root(NULL){
    cout<<"a bst has been constructed"<<endl;
}
template<typename T>
BST<T>::~BST(){
    cout<<"bst has been destroyed"<<endl;
}
template<typename T>
void BST<T>::in_order_traverse(Node<T> * treenode){
    if(treenode){
        in_order_traverse(treenode->leftChild);
        cout<<treenode->data<<endl;
        in_order_traverse(treenode->rightChild);
    }
}
template<typename T>
void BST<T>::print(){
    in_order_traverse(root);
}
template<typename T>
int BST<T>::get_level(Node<T>* treenode){
    if(treenode==NULL) return 0;
    if(treenode->leftChild==NULL&&treenode->rightChild==NULL) {
        treenode->level=1;
        return 1;
    }
    else{
        int left_level=0;
        int right_level=0;
        int result=0;
        if(treenode->leftChild!=NULL) left_level=treenode->leftChild->level;
        if(treenode->rightChild!=NULL) right_level=treenode->rightChild->level;
        if(left_level==0&&right_level==0){
            left_level=get_level(treenode->leftChild);
            right_level=get_level(treenode->rightChild);
        }
        result=1+max(left_level,right_level);
        treenode->level=result;
        return result;

    }
        
}
template<typename T>
void BST<T>::set_level(){
    get_level(root);
}
template<typename T>
void BST<T>::insert(T val){
    Node<T> * newnode=new Node<T>(val);
    Node<T> * leading=root;
    Node<T> * trailing=leading;
    while(leading){
        trailing=leading;
        if(val<leading->data) leading=leading->leftChild;
        else leading=leading->rightChild;
    }
    if(trailing==NULL) root=newnode;
    else{
        newnode->parent=trailing;
        if(val<trailing->data) trailing->leftChild=newnode;
        else trailing->rightChild=newnode;
    }
}
template<typename T>
void BST<T>::build_tree(vector<T> & input_data){
    for(auto x:input_data){
        insert(x);
    }
    set_level();    
}
template<typename T>
void BST<T>::matrix_print(){
int height=root->level;
int n=pow(2,height)-1;
int position=(n-1)/2;
int offset=(position+1)/2;
vector<vector<string>> result(height,vector<string>(n," "));

layout(root,result,0,position,offset);
int i=0;
for (auto x:result){
    for (auto y:result[i]){
        cout<<y;
    }
    cout<<endl;
    ++i;
}

}
template<typename T>
void BST<T>::layout(Node<T>* treenode, vector<vector<string>> &result,int layer, int position, int offset){
    if(treenode==NULL) return;
    result[layer][position]=to_string(treenode->data);
    layout(treenode->leftChild,result,layer+1,position-offset,offset/2);
    layout(treenode->rightChild,result,layer+1,position+offset,offset/2);
}
template<typename T>
void BST<T>::level_order_travesal(Node<T> * treenode,vector<vector<T>> & result,int layer){
    if(treenode==NULL) return;
    result[layer].push_back(treenode->data);
    level_order_travesal(treenode->leftChild,result,layer+1);
    level_order_travesal(treenode->rightChild,result,layer+1);

}
template<typename T>
void BST<T>::level_print(){
    vector<vector<T>> result(root->level);
    level_order_travesal(root,result,0);
    int i=0;
    for(auto x:result){
        for (auto y:result[i]){
            cout<<y;
        }
        ++i;
        cout<<endl;
    }
}
template<typename T>
void BST<T>::Path(Node<T> * treenode, vector<T>& path, vector<vector<T>>& paths){
    
    if(treenode==NULL) return;
    path.push_back(treenode->data);
    if(treenode->leftChild==NULL&&treenode->rightChild==NULL){
        paths.push_back(path);
        return;
    }
    vector<T> path_left=path;
    vector<T> path_right=path;
    
        Path(treenode->leftChild, path_left, paths);
        Path(treenode->rightChild, path_right, paths);
        //path.pop_back();
}
template<typename T>
void BST<T>::path_print(){
    vector<T> path;
    vector<vector<T>> paths;
    Path(root, path, paths);
    int i=0;
    for(auto x:paths){
        for(auto y:paths[i]){
            cout<<y<<" ";
        }
        ++i;
        cout<<endl;
    }
}
