# Binary Search Tree Traversal Demonstration

## Overview

This project is a small C/C++ demonstration of a binary search tree-like structure. Its main purpose is not to build a complete binary search tree implementation, but to show one important design pattern used constantly in tree code:

> A public method gives the outside program a clean interface, while a private recursive helper method performs the actual recursive work inside the tree.

The example creates a hardcoded tree, then prints the nodes using an in-order traversal.

## Files

| File | Purpose |
|---|---|
| `main.cpp` | Creates test data, constructs the demonstration tree, and calls `displayInOrder()` |
| `main.h` | Includes common headers, defines `TESTDATA`, and includes `bintree.h` |
| `bintree.h` | Declares the `BinTree` class, including the public method and private recursive helper |
| `bintree.cpp` | Implements the tree constructors and the in-order traversal methods |
| `data.h` | Defines the `Data` and `DataNode` structures used by the tree |

## What the Program Demonstrates

The program creates this test data:

```cpp
int ids[TESTDATA] = {60, 20, 70, 40, 10, 50, 30};
string strings[TESTDATA] = {"sixty", "twenty", "seventy", "forty", "ten", "fifty", "thirty"};
```

The demonstration constructor manually builds the following tree:

```text
          60
        /    \
      20      70
     /  \
   10    40
        /  \
      30    50
```

This tree follows the binary search tree ordering rule:

- Values smaller than a node go to the left.
- Values greater than a node go to the right.

The program then calls:

```cpp
binSearchTree.displayInOrder();
```

Because this is an in-order traversal, the nodes are displayed in sorted order by ID.

Expected output:

```text
Binary Search Tree created

Displaying In Order
===================
10 ten
20 twenty
30 thirty
40 forty
50 fifty
60 sixty
70 seventy
```

## Important Warning About the Demonstration Constructor

The constructor below is included only for demonstration:

```cpp
BinTree::BinTree(int ids[], string strings[])
```

This constructor manually creates a fixed tree using known test data. It is useful for proving that traversal works, but it is not a proper general-purpose binary search tree constructor.

A real binary search tree should usually start empty:

```cpp
BinTree::BinTree() {
    root = NULL;
}
```

Then nodes should be added one at a time using an `addNode` or `insert` method.

## The Key Design Pattern: Public Wrapper + Private Recursive Helper

The most important idea in this code is the structure of `displayInOrder`.

In `bintree.h`, there are two methods with the same name:

```cpp
public:
    void displayInOrder();

private:
    void displayInOrder(DataNode*);
```

This is method overloading. The two methods have the same name, but they have different parameter lists.

The public version takes no parameters:

```cpp
void displayInOrder();
```

The private version takes a pointer to a node:

```cpp
void displayInOrder(DataNode*);
```

These two methods have different jobs.

## The Public Method

The public method is the method that outside code is allowed to call:

```cpp
void BinTree::displayInOrder() {
    displayInOrder(root);
}
```

From `main.cpp`, the user only needs to write:

```cpp
binSearchTree.displayInOrder();
```

That is exactly what we want. The user of the class should not need to know where the root is stored. The user should not need to pass a node pointer. The user should not need to understand the internal memory structure of the tree.

The public method gives the class a simple external interface:

```cpp
tree.displayInOrder();
```

That means:

> Display the entire tree in order.

## The Private Recursive Helper

The private helper method does the actual recursive traversal:

```cpp
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
```

This method needs a `DataNode*` because recursion works by solving the same problem on smaller parts of the structure.

For a tree, the smaller parts are subtrees.

At any point in the traversal, `temproot` means:

> The current node being visited in this recursive call.

The recursive method follows the in-order traversal pattern:

```text
visit left subtree
visit current node
visit right subtree
```

That is why the output is sorted for a binary search tree.

## Why Not Make the Recursive Method Public?

It would be bad design to make this method public:

```cpp
void displayInOrder(DataNode*);
```

The outside program should not have access to the tree's internal node pointers.

There are several reasons.

First, `root` is private. Outside code cannot access it directly:

```cpp
DataNode *root;
```

That is intentional. The `BinTree` object owns its internal structure.

Second, external code should not be responsible for passing node pointers into traversal methods. This would make the class harder to use and easier to misuse.

Third, if outside code could pass arbitrary node pointers into the tree, the tree could be traversed incorrectly, skipped, or possibly corrupted in more advanced methods.

The public/private design protects the abstraction.

The outside program says what it wants:

```cpp
display the tree
```

The tree class decides how to do it internally.

## Why Recursive Tree Methods Usually Need a Helper

A public tree method usually represents an operation on the whole tree:

```cpp
displayInOrder();
addNode(id, information);
contains(id);
getHeight();
clear();
```

But the recursive algorithm usually needs to know which node it is currently processing.

That creates a mismatch.

The outside user wants this:

```cpp
tree.displayInOrder();
```

But the recursive logic needs this:

```cpp
displayInOrder(currentNode);
```

The solution is to use two methods:

```text
public method:
    starts the operation from root

private helper:
    recursively processes one node or subtree at a time
```

For this program:

```cpp
void BinTree::displayInOrder() {
    displayInOrder(root);
}
```

The public method starts the process at the root. After that, the private method handles the recursive calls.

## General Pattern for Recursive Tree Methods

This same structure applies to most binary tree operations.

### Traversal

```cpp
public:
    void displayInOrder();

private:
    void displayInOrder(DataNode*);
```

The public method starts at `root`. The private method recursively visits nodes.

### Searching

A search method might be structured like this:

```cpp
public:
    bool contains(int id);

private:
    bool contains(DataNode*, int id);
```

The public method might call:

```cpp
return contains(root, id);
```

The private method would recursively move left or right until it finds the value or reaches the end of the tree.

### Inserting

An insert method might be structured like this:

```cpp
public:
    bool addNode(int id, string information);

private:
    bool addNode(DataNode**, int id, string information);
```

or, depending on the design:

```cpp
private:
    DataNode* addNode(DataNode*, int id, string information);
```

The exact parameter style may vary, but the principle is the same:

- The public method accepts clean user-level data.
- The private helper receives node pointers and performs the recursive tree logic.

### Clearing or Destroying the Tree

A destructor or clear method often uses the same pattern:

```cpp
public:
    void clear();

private:
    void clear(DataNode*);
```

The public method begins at `root`. The private helper recursively deletes the left subtree, deletes the right subtree, and then deletes the current node.

## Why In-Order Traversal Prints Sorted Output

For a binary search tree, every node follows this rule:

```text
left child < current node < right child
```

In-order traversal uses this order:

```text
left subtree
current node
right subtree
```

So, when the tree is a valid binary search tree, in-order traversal visits the values from smallest to largest.

That is why this tree:

```text
          60
        /    \
      20      70
     /  \
   10    40
        /  \
      30    50
```

prints as:

```text
10
20
30
40
50
60
70
```

The traversal is not sorting the values directly. The values are already organized by the binary search tree structure. The traversal simply visits them in the correct order.

## Compiling and Running

If the files are named normally:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp bintree.cpp -o bst_demo
./bst_demo
```

If the uploaded main file is still named `main(3).cpp`, compile it like this:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic 'main(3).cpp' bintree.cpp -o bst_demo
./bst_demo
```

## Student Takeaways

The important lessons from this example are:

1. Tree recursion usually needs a current node pointer.
2. The outside user of the class should not manage internal node pointers.
3. A public method provides a clean interface.
4. A private helper method performs the recursive work.
5. The public method usually starts the private helper at `root`.
6. In-order traversal of a valid binary search tree prints the data in sorted order.
7. The hardcoded constructor is only for demonstration; a complete tree class should insert nodes dynamically.

## Conceptual Summary

The public method answers the question:

> What does the user want to do with the tree?

The private recursive helper answers the question:

> Where am I currently inside the tree while doing that work?

That separation is one of the central design patterns in recursive data structures.
