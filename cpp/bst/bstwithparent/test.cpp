
#include<iostream>
#include<vector>
#include "bst.hpp"
using namespace std;

int main(){
    vector<int> input={8,12,4,9,2,14,11,1,3,5,13,10,7,15,6};
    BST<int> bst;
    bst.build_tree(input);
    //bst.print();
    //bst.matrix_print();
    bst.level_print();
    return 0;
}
