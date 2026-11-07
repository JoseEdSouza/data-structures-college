#pragma once

#include <iostream>
template<typename T>
struct Node {
    T data;
    Node* rnode;
    Node* lnode;
    std::string query;
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
    void ask_rec(Node<T>* root);

public:
    DecisionTreeDoPae();
    DecisionTreeDoPae(T value);
    DecisionTreeDoPae(Node<T>* root);
    ~DecisionTreeDoPae();

    void set_root(Node<T>* root);
    bool empty();
    bool is_leaf();

    void clear();

    void ask();
};

#include "decisionTreeDoPae.cpp"