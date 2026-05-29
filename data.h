/* *************************************************
*  Name: Alexander Katrompas
*  Assignment: Demonstration Code
*  Purpose: This code defines the Data and DataNode structures used in a binary tree.
************************************************* */

#ifndef DATA_H
#define DATA_H

#include <string>

struct Data {
    int id;
    std::string information;
};

struct DataNode {
    Data data;
    DataNode *left, *right;
};

#endif /* DATA_H */
