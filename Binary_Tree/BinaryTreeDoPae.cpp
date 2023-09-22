/* The code you provided is the implementation of a binary search tree class called `BinaryTreeDoPae`
in C++. */
#ifndef BINARYTREEDOPAE_CPP
#define BINARYTREEDOPAE_CPP
#include "BinaryTreeDoPae.h"
/* The `#define header template<typename T>` is a preprocessor directive that defines a macro named
"header". This macro is used to replace the text "header" with "template<typename T>" in the code.
It is commonly used in C++ to define template classes or functions. */
#define header template<typename T>

header BinaryTreeDoPae<T>::BinaryTreeDoPae() {
    m_root = nullptr;
    m_size = 0;
}

header BinaryTreeDoPae<T>::BinaryTreeDoPae(T value) {
    m_root = new Node(value);
    m_size = 1;
}

header BinaryTreeDoPae<T>::BinaryTreeDoPae(std::initializer_list<T> initial) {
    m_size = 0;
    m_root = nullptr;
    if (std::empty(initial)) return;
    for (T elem : initial) {
        this->insert(elem);
    }
}

header BinaryTreeDoPae<T>::~BinaryTreeDoPae() {
    clear();
}

header size_t BinaryTreeDoPae<T>::size() {
    return m_size;
}

header bool BinaryTreeDoPae<T>::empty() {
    return m_root == nullptr;
}

header bool BinaryTreeDoPae<T>::is_leaf() {
    return !empty() && m_root->lnode == nullptr && m_root->rnode == nullptr;
}

header void BinaryTreeDoPae<T>::insert(T value) {
    if (empty()) m_root = insert_rec(m_root, new Node(value));
    else insert_rec(m_root, new Node(value));
    ++m_size;
}

header typename BinaryTreeDoPae<T>::Node* BinaryTreeDoPae<T>::insert_rec(Node* root, Node* node) {
    if (root == nullptr) {
        return node;
    }
    if (node->data < root->data)
        root->lnode = insert_rec(root->lnode, node);
    else
        root->rnode = insert_rec(root->rnode, node);

    return root;
}


header bool BinaryTreeDoPae<T>::remove(T value) {
    if (!contains(value)) return false;
    remove_rec(m_root, value);
    --m_size;
    return true;
}

header typename BinaryTreeDoPae<T>::Node* BinaryTreeDoPae<T>::remove_rec(Node* root, T value) {
    if (root == nullptr) return nullptr;
    if (value < root->data)
        root->lnode = remove_rec(root->lnode, value);
    else if (value > root->data)
        root->rnode = remove_rec(root->rnode, value);
    else {
        if (root->lnode == nullptr && root->rnode == nullptr) {
            delete root;
            return nullptr;
        }
        else if (root->rnode != nullptr) {
            root->data = node_successor(root);
            root->rnode = remove_rec(root->rnode, root->data);
        }
        else {
            root->data = node_predecessor(root);
            root->lnode = remove_rec(root->lnode, root->data);
        }
    }
    return root;
}

header T BinaryTreeDoPae<T>::node_successor(Node* root) {
    Node* iNode = root->rnode;
    while (iNode->lnode != nullptr) {
        iNode = iNode->lnode;
    }
    return iNode->data;
}

header T BinaryTreeDoPae<T>::node_predecessor(Node* root) {
    Node* iNode = root->lnode;
    while (iNode->rnode != nullptr) {
        iNode = iNode->rnode;
    }
    return iNode->data;
}

header void BinaryTreeDoPae<T>::clear() {
    clear_rec(m_root);
    m_root = nullptr;
    m_size = 0;
}

header void BinaryTreeDoPae<T>::clear_rec(Node* root) {
    if (root != nullptr) {
        clear_rec(root->lnode);
        clear_rec(root->rnode);
        delete root;
    }
}

header bool BinaryTreeDoPae<T>::contains(T value) {
    return contains_rec(m_root, value);
}

header bool BinaryTreeDoPae<T>::contains_rec(Node* root, T value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;
    else if (root->data > value) return contains_rec(root->lnode, value);
    else return contains_rec(root->rnode, value);
}

header void BinaryTreeDoPae<T>::print_values() {
    if (empty()) return;
    print_values_rec(m_root);
    std::cout << "\n";
}

header void BinaryTreeDoPae<T>::print_values_rec(Node* root) {
    if (root == nullptr) return;
    print_values_rec(root->lnode);
    std::cout << root->data << " ";
    print_values_rec(root->rnode);
}

header T BinaryTreeDoPae<T>::max() {
    if (empty()) return -1;
    return max_rec(m_root);
}

header T BinaryTreeDoPae<T>::max_rec(Node* root) {
    if (root->rnode == nullptr) return root->data;
    return max_rec(root->rnode);
}

header T BinaryTreeDoPae<T>::min() {
    if (empty()) return -1;
    return min_rec(m_root);
}

header T BinaryTreeDoPae<T>::min_rec(Node* root) {
    if (root->lnode == nullptr) return root->data;
    return min_rec(root->lnode);
}

#undef header
#endif
