#include <vector>
#include <iostream>
#include <string>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

template<typename T>
class HEAP{
    private:
        vector<T> data;
        //note that queue does not have iterator associated with it
        int length;
        void decrease_len();
        //the indexing can be a bit tricky if starting from zero. to make things easier, just starting from 1 instead.
        int parent(int i){return i/2;}
        int left(int i){return 2*i;}
        int right(int i){return 2*i+1;}
        void max_heapify(int i);
        void swap(int i, int j);
        int len();
    public:
        HEAP();
        HEAP(vector<T>);
        ~HEAP();
        void print();
        void build_max_heap();
        //void build_min_heap();
        void heap_sort();
        void insert(T);
        //void increase_key(XXXX, T);
};

template class HEAP<int>;
template class HEAP<double>;
template class HEAP<string>;
#endif
