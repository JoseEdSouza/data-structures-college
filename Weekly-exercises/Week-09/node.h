#ifndef NODE_H
#define NODE_H

template<typename T>
class Node {
private:
    T value;  // valor 
    Node<T>* left;  // ponteiro para filho esquerdo
    Node<T>* right;  // ponteiro para filho direito
public:
    /**
     * Construtor que recebe o valor que o nó irá armazenar e os ponteiros para os
     * filhos esquerdo e direito, respectivamente.
     * */
    Node(T val, Node<T>* l=nullptr, Node<T>* r=nullptr);

    /**
    Métodos gets e sets dos atributos
    **/
    T getValue();
    Node<T>* getLeft();
    Node<T>* getRight();


    void setValue(T newValue);
    void setLeft(Node<T>* newLeft);
    void setRight(Node<T>* newRight);
};
#include "node.cpp"
#endif
