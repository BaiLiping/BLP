
#include<iostream>
#include<queue>
#include<stack>
#include"graph.h"
using namespace std;

template<typename T>
Graph<T>::Graph():head(NULL),tail(NULL),numEdges(0),numVertices(0){
    cout<<"A Graph has been Constructed"<<endl;
}
template<typename T>
Graph<T>::~Graph(){
    cout<<"A Graph has been Destroyed"endl;
}
template<typename T>
bool Empty(){
    return (numVertices==0);
}
template<typename T>
bool Exist(T v) const{
    if (Empty) return false;

    

}
template<typename T>
void Graph<T>::add(T v1, T v2, int w){
   if ()
    Vertex<T> * vertex1=new Vertex<T>(v1);
    Vertex<T> * vertex2=new Vertex<T>(v2);
    vertex1->addEdge(v2,w);
    vertex1->setNextVertex(vertex2);
    vertex2=>addEdge(v1,w);
    headVertex=vertex1;
    
