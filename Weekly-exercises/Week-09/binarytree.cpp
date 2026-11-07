#ifndef BINARYTREE_CPP
#define BINARYTREE_CPP

#include <iostream>
#include "binarytree.h"
#define header template<typename T>

header BinaryTree<T>::BinaryTree() {
    root = nullptr;
}

header BinaryTree<T>::BinaryTree(T value) {
    root = new Node<T>(value, nullptr, nullptr);
}

header BinaryTree<T>::BinaryTree(T value, BinaryTree<T>& l, BinaryTree<T>& r) {
    root = new Node<T>(value, l.getRoot(), r.getRoot());
    //As duas árvores ficarão vazias, pois os nós raizes delas serão filhas da árvore criada
    l.setRoot(nullptr);
    r.setRoot(nullptr);
}

header Node<T>* BinaryTree<T>::getRoot() {
    return root;
}

header void BinaryTree<T>::setRoot(Node<T>* newRoot) {
    root = newRoot;
}

//Implementei uma função recursiva para liberar os nós de forma recursiva
header void clear_rec(Node<T>* node) {
    if (node != nullptr) {
        clear_rec(node->getLeft());
        clear_rec(node->getRight());
        delete node;
    }
}


header void BinaryTree<T>::clear() {
    clear_rec(root);
    root = nullptr;
}

header BinaryTree<T>::~BinaryTree() {
    clear();
}

header bool BinaryTree<T>::is_empty() {
    return root == nullptr;
}

header void print_values_rec(Node<T>* node) {
    if (node != nullptr) {
        std::cout << node->getValue() << " ";
        print_values_rec(node->getLeft());
        print_values_rec(node->getRight());
    }
}

header void BinaryTree<T>::print_values() {
    print_values_rec(root);
    std::cout << "\n";
}

header bool BinaryTree<T>::is_leaf() {
    return !is_empty() && root->getLeft() == nullptr && root->getRight() == nullptr;
}

header bool contains_rec(Node<T>* node, T value) {
    if (node == nullptr)
        return false; // subárvore vazia
    else
        return node->getValue() == value || contains_rec(node->getLeft(), value) || contains_rec(node->getRight(), value);
}

header bool BinaryTree<T>::contains(T value) {
    return contains_rec(root, value);
}

#undef header
#endif