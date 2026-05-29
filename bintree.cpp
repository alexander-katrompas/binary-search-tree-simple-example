/* *************************************************
*  Name: Alexander Katrompas
*  Assignment: Demonstration Code
*  Purpose: This code defines the BinTree class, which represents a binary
*           tree data structure. It includes a constructor, a method to display
*           the tree in order, and a private member variable for the root of the tree.
*           The class also includes a private helper method for displaying the tree in
*           order starting from a given node.
************************************************* */

#include "bintree.h"

BinTree::BinTree() {
    /* ********************************************************************
     * @breif: this is the correct constructor, you can use this in your
     *         assignment. It initializes the root of the tree to NULL,
     *         indicating that the tree is initially empty. This constructor
     *         does not take any parameters and does not perform any
     *         additional operations.
     *
     * @param : none
     * @exception : none
     * @return : void
     * *******************************************************************/
    root = NULL;
}

BinTree::BinTree(int ids[], string strings[]) {
    /* ********************************************************************
    * @breif: this is NOT a correct constructor,you CANNOT use this assignments
     *        this is an alternate constructor for demonstration
     *        purposes only. This builds a hard coded tree
     *        based on the known test data. It is simply for
     *        demonstration and proving displayInOrder traversal.
     *
     * @param ids : an array of integers representing the IDs for the nodes in the binary tree.
     * @param strings : an array of strings representing the information for the nodes in the binary tree.
     * @exception : none
     * @return : void
     * *******************************************************************/

    root = new DataNode;
    root->left = NULL;
    root->right = NULL;
    root->data.id = ids[0];
    root->data.information = strings[0];

    root->left = new DataNode;
    root->left->left = NULL;
    root->left->right = NULL;
    root->left->data.id = ids[1];
    root->left->data.information = strings[1];

    root->right = new DataNode;
    root->right->left = NULL;
    root->right->right = NULL;
    root->right->data.id = ids[2];
    root->right->data.information = strings[2];

    root->left->right = new DataNode;
    root->left->right->left = NULL;
    root->left->right->right = NULL;
    root->left->right->data.id = ids[3];
    root->left->right->data.information = strings[3];
    
    root->left->left = new DataNode;
    root->left->left->left = NULL;
    root->left->left->right = NULL;
    root->left->left->data.id = ids[4];
    root->left->left->data.information = strings[4];
    
    root->left->right->right = new DataNode;
    root->left->right->right->left = NULL;
    root->left->right->right->right = NULL;
    root->left->right->right->data.id = ids[5];
    root->left->right->right->data.information = strings[5];
    
    root->left->right->left = new DataNode;
    root->left->right->left->left = NULL;
    root->left->right->left->right = NULL;
    root->left->right->left->data.id = ids[6];
    root->left->right->left->data.information = strings[6];

    return;
}

/*
 The structure of displayInOrder is the standard way to implement recursion in
 a case like this. You will have a public method that is called by the user,
 and then a private helper method that actually performs the recursive traversal.
 The reason for this is that the user should not have to know about the internal
 structure of the tree or how to call the recursive method, and cannot have access
 to root. The public method can simply call the private helper method starting from
 the root of the tree, and the private helper method can handle the traversal
 logic without exposing it to the user. This separation of concerns makes the code
 cleaner and easier to use, as the user can simply call displayInOrder() without
 needing to worry about the details of how the tree is structured or how the
 recursion works.

 All the recursive methods will be similar to this. For example, to implement addNode,
 you would have a public addNode method that takes the data to be added, and then a
 private helper method that takes a DataNode pointer and the data to be added.
 The public addNode method would call the private helper method starting from the
 root of the tree, and the private helper method would handle the logic for finding
 the correct location to add the new node based on the binary search tree properties.
 This way, the user can simply call addNode(id, data) without needing to worry about how
 the tree is structured or how to navigate it to find the correct location for the new node.

*/


void BinTree::displayInOrder() {
    /* ********************************************************************
     * @breif: this is the correct displayInOrder method, you can use this in your assignment.
     *         It calls the private helper method displayInOrder(DataNode*) starting from the root of the tree.
     *
     * @param : none
     * @exception : none
     * @return : void
     * *******************************************************************/
    displayInOrder(root);
}

void BinTree::displayInOrder(DataNode *temproot) {
    /* ********************************************************************
     * @breif: this is the correct displayInOrder helper method, you can use this in your assignment.
     *         It performs an in-order traversal of the binary tree starting from the given node (temproot).
     *         The method recursively visits the left subtree, prints the current node's data, and then visits the right subtree.
     *
     * @param temproot : a pointer to a DataNode representing the current node in the binary tree during the traversal.
     * @exception : none
     * @return : void
     * *******************************************************************/
    
    if (temproot) {
        if (temproot->left) {
            displayInOrder(temproot->left);
        }
        cout << temproot->data.id << " " << temproot->data.information << endl;
        if (temproot->right) {
            displayInOrder(temproot->right);
        }
    }

    return;
}

