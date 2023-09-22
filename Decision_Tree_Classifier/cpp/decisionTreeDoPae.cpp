/**
 * decisionTreeDoPae.cpp
 *
 * This file contains the implementation of the methods of the `DecisionTreeDoPae` class defined in the
 * `decisionTreeDoPae.h` file. The class is responsible for providing the logic to interact with the
 * decision tree for disease diagnosis, including tree construction, asking questions to the user, and
 * obtaining the final diagnosis based on the provided answers.
 *
 * Author: José Vinícius Evangelista Dias de Souza
 */

#ifndef DECISIONTREEDOPAE_CPP
#define DECISIONTREEDOPAE_CPP
#include "decisionTreeDoPae.h"
#include <iostream>
#define header template<typename T>


header DecisionTreeDoPae<T>::DecisionTreeDoPae() {
    m_root = nullptr;
}

header DecisionTreeDoPae<T>::DecisionTreeDoPae(T value) {
    m_root = new Node(value);
}

header DecisionTreeDoPae<T>::DecisionTreeDoPae(Node<T>* root){
    this->m_root = root;
}

header DecisionTreeDoPae<T>::~DecisionTreeDoPae() {
    clear();
}

header void DecisionTreeDoPae<T>::set_root(Node<T>* root){
    clear(m_root);
    m_root = root;
}
header bool DecisionTreeDoPae<T>::empty() {
    return m_root == nullptr;
}

header bool DecisionTreeDoPae<T>::is_leaf() {
    return !empty() && m_root->lnode == nullptr && m_root->rnode == nullptr;
}

header void DecisionTreeDoPae<T>::clear() {
    clear_rec(m_root);
    m_root = nullptr;
}

header void DecisionTreeDoPae<T>::clear_rec(Node<T>* root) {
    if (root != nullptr) {
        clear_rec(root->lnode);
        clear_rec(root->rnode);
        delete root;
    }
}


header void DecisionTreeDoPae<T>::ask(){
    if (empty()) return;
    ask_rec(m_root);
}

header void DecisionTreeDoPae<T>::ask_rec(Node<T>* root) {
    if (root == nullptr)
        return;

    if (root->query != "") {
        std::string answer;
        std::cout <<"Sympton: "<< root->query << "? (yes/no) ";
        std::cin >> answer;

        if (answer == "yes") {
            ask_rec(root->rnode);
        } else if (answer == "no") {
            ask_rec(root->lnode);
        } else {
            std::cout << "Invalid answer. Please answer with yes or no.\n";
            ask_rec(root);
        }
    } else {
        std::cout << "The diagnosis is: " << root->data << "\n";
    }
}


#undef header
#endif