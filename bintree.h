/* *************************************************
*  Name: Alexander Katrompas
*  Assignment: Demonstration Code
*  Purpose: This code defines the BinTree class, which represents a binary
*           tree data structure. It includes a constructor, a method to display
*           the tree in order, and a private member variable for the root of the tree.
*           The class also includes a private helper method for displaying the tree in
*           order starting from a given node.
************************************************* */

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

    // this is a standard constructor, you can use this in your assignment
    BinTree();
    
    // this is NOT a correct constructor, you CANNOT use this assignments
    // the purpose of this constructor is to demonstrate building a hard coded tree
    // based on the known test data. It is simply for demonstration and proving displayInOrder traversal.
    BinTree(int[], string[]);

    //this is a correct solution you can use in your assignment
    void displayInOrder();

private:

    DataNode *root;

    //this is a correct solution you can use in your assignment
    void displayInOrder(DataNode*);
};

#endif /* BINTREE_H */
