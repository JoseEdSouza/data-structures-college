/**
 * decisionTreeDoPae.h
 *
 * This file contains the definition of a class `DecisionTreeDoPae` that implements the logic to interact with
 * the decision tree for disease diagnosis. The class provides methods to build the tree, ask questions to the
 * user, and obtain the final diagnosis based on the provided answers.
 *
 * The `DecisionTreeDoPae` class is built on top of the data structure of a binary tree, where each node of the
 * tree is represented by the `Node` structure defined in this file.
 *
 * Author: José Vinícius Evangelista Dias de Souza
 */

#pragma once

#include <iostream>
template<typename T>
struct Node {
    T data;
    Node* rnode;
    Node* lnode;
    std::string query; //? query asked to user
    // * leaf constructor
    Node(T elem) {
        data = elem;
        rnode = nullptr;
        lnode = nullptr;
        query = "";
    }
    // * query node constructor
    Node(std::string query, Node* left, Node* right) {
        this->query = query;
        rnode = right;
        lnode = left;
        data = "";
    }
};

template <typename T>
class DecisionTreeDoPae {
private:
    Node<T>* m_root;

    Node<T>* insert_rec(Node<T>* root, Node<T>* node);
    void clear_rec(Node<T>* root);
    
    //* recursive method that assists ask method
    void ask_rec(Node<T>* root);

public:
    DecisionTreeDoPae(); //? default constructor
    DecisionTreeDoPae(T value); 
    DecisionTreeDoPae(Node<T>* root); //? constructor with root node
    ~DecisionTreeDoPae(); //* destructor

    void set_root(Node<T>* root);
    
    //* checks if the tree is empty
    bool empty();
    
    //* checks if the tree is a leaf
    bool is_leaf();

    //* clear the tree
    void clear();

    //* method to ask user and calculate the prognosis given the yes or no answers by the user
    void ask();
};

#include "decisionTreeDoPae.cpp"