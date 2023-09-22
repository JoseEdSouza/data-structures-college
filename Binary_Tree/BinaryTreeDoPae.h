/**
 * The above code is implementing a binary tree data structure using templates in C++. 
 * It defines a class called `BinaryTreeDoPae` that represents a binary tree.
 * The binary tree is implemented using a linked structure, 
 * where each node contains a data element and pointers to its left and right child nodes.*/
#pragma once

#include <iostream>

/**The `class BinaryTreeDoPae` is implementing a binary tree data structure using templates in C++.
 *It represents a binary tree and provides various methods to manipulate and access the elements of the tree.
 *The binary tree is implemented using a linked structure, where each node contains a data element and pointers to its left and right child nodes.
 *The class provides methods for inserting nodes, removing nodes, checking if a value exists in the tree, finding the maximum and minimum values in the tree,
 *clearing the tree, and printing the values of the nodes in a specific order.
 */
template <typename T>
class BinaryTreeDoPae {
private:
    /**The `struct Node` is defining a node structure for the binary tree. 
    *It contains three members: `data`, `rnode`, and `lnode`.
    */
    struct Node {
        T data;
        Node* rnode;
        Node* lnode;
        Node(T elem) {
            data = elem;
            rnode = nullptr;
            lnode = nullptr;
        }
    };

    size_t m_size;
    /**The Node* m_root;` is declaring a private member variable `m_root` of type `Node*` in the `BinaryTreeDoPae` class. 
    *This variable represents the root node of the binary tree.
    *It is a pointer to the first node in the tree, from which all other nodes can be accessed
    */
    Node* m_root;

    /**
    * The function recursively inserts a node into a binary tree.
    * 
    * @param root The root parameter is a pointer to the root node of the binary tree.
    * @param node The "node" parameter is a pointer to the node that we want to insert into the binary
    * tree.
    * 
    * @return a pointer to a Node.
    */
    Node* insert_rec(Node* root, Node* node);
    /**
    * The function recursively clears a binary tree by deleting each node.
    * 
    * @param root The parameter "root" is a pointer to the root node of a binary tree.
    */
    void clear_rec(Node* root);
    /**
    * The function checks if a binary tree contains a specific value recursively.
    * 
    * @param root The root parameter is a pointer to the root node of the binary tree.
    * @param value The "value" parameter represents the value that we are searching for in the binary
    * tree.
    * 
    * @return a boolean value.
    */
    bool contains_rec(Node* root, T value);
    /**
    * The function recursively prints the values of a binary tree in a specific order.
    * 
    * @param root The "root" parameter is a pointer to the root node of a binary tree.
    * 
    * @return void.
    */
    void print_values_rec(Node* root);
    /**
    * The function removes a node with a specific value from a binary tree recursively.
    * 
    * @param root The parameter "root" is a pointer to the root node of the binary tree.
    * @param value The parameter "value" represents the value that needs to be removed from the binary
    * tree.
    * 
    * @return a pointer to the root node of the binary tree.
    */
    Node* remove_rec(Node* root, T value);
    /**
    * The function finds the successor node in a binary tree.
    * 
    * @param root The "root" parameter is a pointer to the root node of a binary tree.
    * 
    * @return The data of the node that is the successor of the given root node in a binary tree.
    */
    T node_successor(Node* root);
    /**
    * The function finds the predecessor of a given node in a binary tree.
    * 
    * @param root The root parameter is a pointer to the root node of the binary tree.
    * 
    * @return The data of the node that is the predecessor of the given root node in a binary tree.
    */
    T node_predecessor(Node* root);
    /**
    * The function recursively finds and returns the maximum value in a binary tree.
    * 
    * @param root The "root" parameter is a pointer to the root node of a binary tree.
    * 
    * @return The maximum value in the binary tree.
    */
    T max_rec(Node* root);
    /**
    * The function recursively finds the minimum value in a binary tree.
    * 
    * @param root The "root" parameter is a pointer to the root node of the binary tree.
    * 
    * @return The minimum value in the binary tree.
    */
    T min_rec(Node* root);

public:
    BinaryTreeDoPae();
    /**
    * The constructor for the BinaryTreeDoPae class initializes a new binary tree with a root node
    * containing the given value.
    * 
    * @param value The value parameter represents the value that will be stored in the root node of the
    * binary tree.
    */
    BinaryTreeDoPae(T value);
    /**
    * The constructor for the BinaryTreeDoPae class initializes a new binary tree with a root node
    * containing the given value.
    *
    * @param value The value parameter represents the value that will be stored in the root node of the
    * binary tree.
    */
    BinaryTreeDoPae(std::initializer_list<T> initial);
    /**
    * The destructor for the BinaryTreeDoPae class, which clears all elements in the binary tree.
    */
    ~BinaryTreeDoPae();

    /**
    * The function returns the size of the binary tree.
    * 
    * @return The size of the binary tree.
    */
    size_t size();

    /**
    * The function checks if the binary tree is empty.
    * 
    * @return a boolean value.
    */
    bool empty();
    /**
    * The function checks if the binary tree is a leaf node.
    * 
    * @return a boolean value.
    */
    bool is_leaf();
    /**
    * The function checks if a binary tree contains a specific value.
    * 
    * @param value The value parameter represents the value that we are searching for in the binary tree.
    * 
    * @return a boolean value.
    */
    bool contains(T value);

    /**
    * The function inserts a new node with the given value into a binary tree.
    * 
    * @param value The value to be inserted into the binary tree.
    */
    void insert(T value);
    /**
    * The function removes a value from a binary tree if it exists and returns true, otherwise it returns
    * false.
    * 
    * @param value The parameter "value" is of type T, which represents the value that needs to be removed
    * from the binary tree.
    * 
    * @return The method is returning a boolean value.
    */
    bool remove(T value);
    /**
    * The clear() function clears all nodes in the binary tree and resets the root and size.
    */
    void clear();
    /**
    * The function `print_values()` prints the values of the nodes in a binary tree in pre-order
    * traversal.
    * 
    * @return In the given code snippet, nothing is being returned. The return type of the function is
    * "void", which means it does not return any value.
    */
    void print_values();

    /**
    * The function returns the maximum value in a binary tree.
    * 
    * @return The max value in the binary tree.
    */
    T max();
    /**
    * The function returns the minimum value in a binary tree.
    * 
    * @return The minimum value in the binary tree.
    */
    T min();
};

#include "BinaryTreeDoPae.cpp"