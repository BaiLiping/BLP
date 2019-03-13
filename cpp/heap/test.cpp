
#include<iostream>
#include<vector>
#include"heap.h"
using namespace std;

int main(){
    vector<int> d={3,9,7,4,12,6,1};
    HEAP<int> heap(d);
    heap.print();
    heap.build_max_heap();
    heap.print();
   // heap.heap_sort();
   // heap.print();

    return 0;
}
