#include <iostream>
#include <queue>
#include "binarytree.h"
#define header template<typename T>

header void bt_pre_ordem(BinaryTree<T>& bt) {
    std::queue<T> bt_queue;
    bt_pre_ordem_rec(bt.getRoot(), bt_queue);
    while (!bt_queue.empty()) {
        std::cout << bt_queue.front();
        bt_queue.pop();
        if (!bt_queue.empty()) std::cout << " ";
    }
    std::cout << "\n";
}

header void bt_pre_ordem_rec(Node<T>* root, std::queue<T>& _queue) {
    if (root == nullptr) return;
    _queue.push(root->getValue());
    bt_pre_ordem_rec(root->getLeft(), _queue);
    bt_pre_ordem_rec(root->getRight(), _queue);
}

header void bt_pos_ordem(BinaryTree<T>& bt) {
    std::queue<T> bt_queue;
    bt_pos_ordem_rec(bt.getRoot(), bt_queue);
    while (!bt_queue.empty()) {
        std::cout << bt_queue.front();
        bt_queue.pop();
        if (!bt_queue.empty()) std::cout << " ";
    }
    std::cout << "\n";
}

header void bt_pos_ordem_rec(Node<T>* root, std::queue<T>& _queue) {
    if (root == nullptr) return;
    bt_pos_ordem_rec(root->getLeft(), _queue);
    bt_pos_ordem_rec(root->getRight(), _queue);
    _queue.push(root->getValue());
}

header void bt_ordem_simetrica(BinaryTree<T>& bt) {
    std::queue<T> bt_queue;
    bt_ordem_simetrica_rec(bt.getRoot(), bt_queue);
    while (!bt_queue.empty()) {
        std::cout << bt_queue.front();
        bt_queue.pop();
        if (!bt_queue.empty()) std::cout << " ";
    }
    std::cout << "\n";
}

header void bt_ordem_simetrica_rec(Node<T>* root, std::queue<T>& _queue) {
    if (root == nullptr) return;
    bt_ordem_simetrica_rec(root->getLeft(), _queue);
    _queue.push(root->getValue());
    bt_ordem_simetrica_rec(root->getRight(), _queue);
}

header void bt_percurso_largura(BinaryTree<T>& bt) {
    std::queue<T> bt_queue;
    bt_percurso_largura_helper(bt.getRoot(), bt_queue);
    while (!bt_queue.empty()) {
        std::cout << bt_queue.front();
        bt_queue.pop();
        if (!bt_queue.empty()) std::cout << " ";
    }
    std::cout << "\n";
}

header void bt_percurso_largura_helper(Node<T>* root, std::queue<T>& _queue) {
    if (root == nullptr) return;

    std::queue<Node<T>*> node_queue;
    node_queue.push(root);

    while (!node_queue.empty()) {
        Node<T>* iNode = node_queue.front();
        node_queue.pop();

        _queue.push(iNode->getValue());

        if (iNode->getLeft() != nullptr)
            node_queue.push(iNode->getLeft());

        if (iNode->getRight() != nullptr)
            node_queue.push(iNode->getRight());
    }
}

header void execute_all(BinaryTree<T>& bt) {
    bt_pre_ordem(bt);
    bt_pos_ordem(bt);
    bt_ordem_simetrica(bt);
    bt_percurso_largura(bt);
}

int main() {
    Node<int>* no9 = new Node<int>(9);
    Node<int>* no1 = new Node<int>(1, nullptr, no9);
    Node<int>* no6 = new Node<int>(6);
    Node<int>* no7 = new Node<int>(7, no1, no6);

    Node<int>* no4 = new Node<int>(4);
    Node<int>* no8 = new Node<int>(8, no4);
    Node<int>* no3 = new Node<int>(3);
    Node<int>* no5 = new Node<int>(5, no3, no8);

    Node<int>* no2 = new Node<int>(2, no5, no7);

    BinaryTree<int> bt;
    bt.setRoot(no2);
    execute_all(bt);
}

#undef header