/* *************************************************
*  Name: Alexander Katrompas
*  Assignment: Demonstration Code
*  Purpose: This code defines the main function for a demonstration
*           of a binary tree data structure. It initializes test data,
*           creates a binary search tree using the BinTree class, and
*           displays the tree in order. The code includes necessary header
*           files and uses standard output and string types.
************************************************* */

#include "main.h"

int main() {

    /*
     *  test data
     */
    int ids[TESTDATA] = {60, 20, 70, 40, 10, 50, 30};
    string strings[TESTDATA] = {"sixty", "twenty", "seventy", "forty", "ten", "fifty", "thirty"};

    /*
     *  make and display tree
     */

    // this is a demonstration constructor, you CANNOT use this in your assignment
    // it creates a hard coded tree based on the known test data. It is simply for
    // demonstration and proving displayInOrder traversal.
    BinTree binSearchTree(ids, strings);
    cout << endl << "Binary Search Tree created" << endl << endl;

    cout << "Displaying In Order" << endl;
    cout << "===================" << endl;
    binSearchTree.displayInOrder();

    cout << endl;
    return 0;
}
