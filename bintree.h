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
    BinTree();
    
    //this is NOT a correct solution, you CANNOT use this assignments
    void addNodes(int[], string[]);
    
    //this is a correct solution you can use in your assignment
    void displayInOrder();

private:

    DataNode *root;

    //this is a correct solution you can use in your assignment
    void displayInOrder(DataNode*);
};

#endif /* BINTREE_H */

