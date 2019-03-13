#include <string>
#include <vector>
using namespace std;
#ifndef GRAPH_H
#define GRAPH_H
template<typename T>
class LLNode{
    public:
    T data;
    LLNode<T> * next;
    LLNode<T>(T d=0,LLNode * n=NULL):data(d),next(n){};
};
template<typename T>
class VertexNode{
    public:
    T data;
    LLNode<T> * head;
    VertexNode<T>(T d=0,LLNode<T> * h=NULL):data(d), head(h){};
};
template<typename T>
class Graph{
    private:
        vector<VertexNode<T>> g;
        int findNode(T);
    public:
        Graph<T>();
        ~Graph<T>();
        void buildGraph(vector<T>&);
        void addEdge(T,T,int);
        void addVertex(T);
        void printGraph();
};

template class Graph<int>;
template class Graph<double>;
template class Graph<char>;
template class Graph<string>;

#endif
