#ifndef BINARYTREE_H
#define BINARYTREE_H
#include "node.h"

template<typename T>
class BinaryTree {
private:
    Node<T>* root; // Ponteiro para o nó raiz da árvore binária

public:
    //Construtor de uma árvore binária vazia
    BinaryTree();

    //Construtor de uma arvore com o valor do nó raiz
    BinaryTree(T value);

    //Construtor de uma árvore binária com o valor do nó raiz  
    //e as duas sub-árvores esquerda e direita, respectivamente.
    BinaryTree(T value, BinaryTree<T>& l, BinaryTree<T>& r);

    //Retorna o nó raiz
    Node<T>* getRoot();

    //Atualiza o nó raiz
    void setRoot(Node<T>* newRoot);

    //Retorna true se e somente se a árvore estiver vazia
    bool is_empty();

    //Retorna true se e somente se a árvore é uma folha
    bool is_leaf();

    //Verifica se um determinado valor está contido na árvore
    bool contains(T value);

    //Imprime todos os valores armazenado na árvore
    void print_values();

    //Remove todos os elementos da árvore, ou seja, deixa a árvore vazia
    void clear();

    // destrutor: libera memoria alocada
    ~BinaryTree();
};

#include "binarytree.cpp"
#endif