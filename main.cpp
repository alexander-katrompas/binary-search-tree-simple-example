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
    BinTree *binSearchTree = new BinTree;
    binSearchTree->addNodes(ids, strings);
    cout << endl << "Binary Search Tree created" << endl << endl;

    cout << "Displaying In Order" << endl;
    cout << "===================" << endl;
    binSearchTree->displayInOrder();

    cout << endl;
    return 0;
}
