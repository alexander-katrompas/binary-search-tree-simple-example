#ifndef BINTREE_H
#define BINTREE_H

#include <iostream>
#include <string>
#include "data.h"

using std::cout;
using std::endl;
using std::string;

class BinTree {
public:
    // this is the correct constructor
    BinTree();
    
    //this is NOT a correct constructor, you CANNOT use this assignments
    BinTree(int[], string[]);
    
    //this is a correct solution you can use in your assignment
    void displayInOrder();

private:

    DataNode *root;

    //this is a correct solution you can use in your assignment
    void displayInOrder(DataNode*);
};

#endif /* BINTREE_H */
