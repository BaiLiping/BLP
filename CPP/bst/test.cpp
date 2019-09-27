#include<iostream>
#include "bst.h"
using namespace std;

int main(){
    BST<int> tree;
    vector<int> input_data={3,9,5,7,2,1,6,4,5,2};
    tree.buildTree(input_data);
    return 0;
}
