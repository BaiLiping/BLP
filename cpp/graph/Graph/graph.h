
#ifndef GRAPH_H
#define GRAPH_H
using namespace std;
template<typename T>
class Edge{
    private:     
        T destination;
        Edge<T> * nextEdge;
        int weight;
    public:
        Edge(T des,int w=0, Edge<T>* n=NULL):destination(des),weight(w),nextEdge(n){
            cout<<"A edge towards "<<des<<" has been created\n";
        };
        ~Edge(){
            cout"A edge has been destroyed\n";
        }
        void setDestination(T des){
            destination=des;
        };
        void setNext(Edge<T> * n){
            nextEdge=n;
        };
        void setWeight(int w){
            weight=w;
        };
        T getDestination() const{
            return destination;
        };
        Edge<T>* getNext() const{
            return nextEdge;
        };
};

template<typename T>
class Vertex{
    private:
        T data;
        Vertex<T> * nextVertex;
        Edge<T> * firstEdge;
    public:
        Vertex(T d=0, Edge<T>* f=NULL):data(d),firstEdge(f){
            cout<<"A Vertex has been created"<<endl;
        };
        ~Vertex(){
            cout<<"A Vertex has been destroyed"<<endl;
        };
        void setData(T d){
            data=d;
        };
        void setNextVertex(Vertex<T>* v){
            nextVertex=v;
        };
        void setFirstEdge(Edge<T>* f){
            firstEdge=f;
        };
        T getData() const{
            return data;
        };
        Vertex<T>* getNextVertex() const{
            return nextVertex;
        };
        Edge<T>* getFirstEdge() const{
            return firstEdge;
        };
        void addEdge(T v, int w){
            Edge<T> newedge(v, w)
            if (firstEdge==NULL) firstEdge=newedge;
            else{
                newedge->nextEdge=firstEdge->nextEdge;
                firstEdge->nextEdge=newedge;
            }
        };
        void removeEdge(T d){
            XXXXX
        };
};
template<typename T>
class Graph{
    private:
        Vertex<T> * head;
        Vertex<T> * tail;
        int numVertices;
        int numEdges;
        bool Exist(T);
        boll isEmpty();
    public:
        Graph();
        ~Graph();
        int getNumVertices() const;
        int getNumEdges() const;
        void add(T, T, int);
        void DFT(T);
        void BFT(T);
        void clear();
};


#endif
