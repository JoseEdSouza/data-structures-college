#ifndef NODE_CPP
#define NODE_CPP
#define header template<typename T>
#include "node.h"

header Node<T>::Node(T val, Node<T>* l, Node<T>* r) {
    value = val;
    left = l;
    right = r;
}

header T Node<T>::getValue() {
    return this->value;
}

header void Node<T>::setValue(T newValue) {
    this->value = newValue;
}

header Node<T>* Node<T>::getLeft() {
    return this->left;
}

header void Node<T>::setLeft(Node<T>* newLeft) {
    this->left = newLeft;
}

header Node<T>* Node<T>::getRight() {
    return this->right;
}

header void Node<T>::setRight(Node<T>* newRight) {
    this->right = newRight;
}

#undef header
#endif