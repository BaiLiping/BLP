#include<iostream>
#include<string>
#include<vector>
#include "graph.h"
using namespace std;

template<typename T>
Graph<T>::Graph():g({}){
    cout<<"a Graph has been constructed"<<endl;
}
template<typename T>
Graph<T>::~Graph(){
    cout<<"a Graph has been deconstructed"<<endl;
}
template<typename T>
void Graph<T>::buildGraph(vector<T>& inputdata){
    for (auto x: inputdata){
        addVertex(x);
    }
}
template<typename T>
void Graph<T>::addVertex(T data){
    VertexNode<T> newvertex(data);
    g.push_back(newvertex);
}
template<typename T>
void Graph<T>::addEdge(T source, T destination){
    int source_loc=findNode(source);
    LLNode<T> *desnode=new LLNode<T>;
    desnode->data=destination;
    LLNode<T> * pointer=g[source_loc].head;
    if (pointer==NULL) pointer=desnode;
    else{
        while(pointer->next){
            pointer=pointer->next;
        }
    }
    pointer->next=desnode;
}
template<typename T>
int Graph<T>::findNode(T key){
    for (vector<VertexNode<T>>::iterator ptr=g.begin;int i=0;ptr!=g.end();++ptr){
        if(x.key==key) return i;
        ++i;
    }
}
template<typename T>
void Graph<T>::printGraph(){
    for (auto x:g){
        cout<<x.data<<" ";
        if(x.head==NULL) cout<<endl;
        else{
            LLNode<T> * pointer=x.head;
            while(pointer->next){
                cout<<pointer->data<<" ";
                pointer=pointer->next;
            }
            cout<<endl;
        }
    }
}
