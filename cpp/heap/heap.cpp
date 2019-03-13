
#include<iostream>
#include<vector>
#include "heap.h"
using namespace std;

template<typename T>
HEAP<T>::HEAP():data({}),length(data.size()){
    cout<<"a heap has been constructed"<<endl;
}
template<typename T>
HEAP<T>::HEAP(vector<T> d):data(d),length(data.size()){
    cout<<"a heap has been constructed"<<endl;
}
template<typename T>
HEAP<T>::~HEAP(){
    cout<<"a heap has been deconstructed"<<endl;
}
template<typename T>
void HEAP<T>::max_heapify(int i){
    int l=left(i);
    int r=right(i);
    int larger=i;
    if(l<=len()&&data[l-1]>data[i-1]) larger=l;
    if(r<=len()&&data[r-1]>data[larger-1]) larger=r;
    if(larger!=i) {
        swap(i,larger);
        max_heapify(larger);
    }
}
template<typename T>
int HEAP<T>::len(){
    return length;
}
template<typename T>
void HEAP<T>::decrease_len(){
    --length;
}
template<typename T>
void HEAP<T>::swap(int i,int j){
    T temp=data[i-1];
    data[i-1]=data[j-1];
    data[j-1]=temp;
}
template<typename T>
void HEAP<T>::build_max_heap(){
    for(int i=(len()/2);i>=1;--i){
        max_heapify(i);
    }
}
template<typename T>
void HEAP<T>::heap_sort(){
    for(int i=len();i>=2;--i){
        swap(1,i);
        decrease_len();
        max_heapify(1);
    }
}
template<typename T>
void HEAP<T>::print(){
    for(auto x:data){
        cout<<x<<" ";
    }
    cout<<endl;
}

