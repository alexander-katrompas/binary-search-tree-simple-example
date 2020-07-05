#include "bintree.h"

BinTree::BinTree() {
    root = NULL;
}

void BinTree::addNodes(int ids[], string strings[]) {
    //this is NOT a correct solution, you CANNOT use this assignments

    /*
     * This builds a hard coded tree based on the known test data.
     * It is simply for testing and proving displayInOrder traversal
     * and nothing else.
     */
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

void BinTree::displayInOrder(DataNode *temproot) {
    
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

void BinTree::displayInOrder() {
    displayInOrder(root);
}
