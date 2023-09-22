/* This code is the implementation of a linked list data structure in C++. It defines a template class
called `LinkedList` that can store elements of any type. The code includes various member functions
such as constructors, destructor, clear, empty, size, getNode, operator[], at, removeAt, removeAll,
insert, replaceAt, push_back, push_front, pop_back, pop_front, equals, and concat. These functions
perform operations like adding, removing, replacing, and accessing elements in the linked list. The
code also includes necessary header guards and template definitions. */
#ifndef LINKEDLISTDOPAE_CPP
#define LINKEDLISTDOPAE_CPP
#include "linkedListDoPae.hpp"
#define header template<typename T>

header LinkedList<T>::LinkedList() {
    this->m_size = 0;
    this->first = nullptr;
}

header LinkedList<T>::LinkedList(std::initializer_list<T> initial) {
    if (std::empty(initial)) {
        this->first->next = nullptr;
        this->first = nullptr;
        this->m_size = 0;
        return;
    }
    m_size = initial.size();
    bool flag = true;
    Node* iNode;
    for (T element : initial) {
        if (flag) {
            flag = false;
            this->first = iNode = new Node(element);
            this->first->next = iNode;
            continue;
        }
        iNode->next = new Node(element);
        iNode = iNode->next;
    }
}

header LinkedList<T>::~LinkedList() {
    this->clear();
}

header void LinkedList<T>::clear() {
    Node* iNode = this->first;
    this->m_size = 0;
    while (iNode != nullptr) {
        Node* aux = iNode;
        iNode = iNode->next;
        delete aux;
    }
}

header bool LinkedList<T>::empty() const {
    return (this->m_size == 0);
}

header size_t LinkedList<T>::size() const {
    return this->m_size;
}

header typename LinkedList<T>::Node* LinkedList<T>::getNode(size_t index){
    if (index >= m_size || index < 0) throw std::out_of_range("index_out_of_range");
    Node* iNode = this->first;
    for (int i = 0;i != index;++i) {
        iNode = iNode->next;
    }
    return iNode;
}

header T& LinkedList<T>::operator[](size_t index) {
    if (index >= m_size || index < 0) throw std::out_of_range("index_out_of_range");
    Node* iNode = this->first;
    for (int i = 0;i != index;++i) {
        iNode = iNode->next;
    }
    return iNode->data;
}

header const T& LinkedList<T>::operator[](size_t index)const {
    if (index >= m_size || index < 0) throw std::out_of_range("index_out_of_range");
    Node* iNode = this->first;
    for (int i = 0;i != index;++i) {
        iNode = iNode->next;
    }
    return iNode->data;
}

header T LinkedList<T>::at(size_t index) {
    return this->operator[](index);
}

header void LinkedList<T>::removeAt(size_t index) {
    if (index >= m_size || index < 0) throw std::out_of_range("index_out_of_range");
    --m_size;
    if (index == 0) {
        Node* rNode = this->first;
        this->first = this->first->next;
        delete rNode;
        return;
    }
    Node* iNode = this->first;
    for (int i = 0;i < index - 1;++i) {
        iNode = iNode->next;
    }
    Node* rNode = iNode->next;
    iNode->next = iNode->next->next;
    delete rNode;
}

header void LinkedList<T>::removeAll(T value) {
    Node* iNode = this->first;
    for (int i = 0;i < m_size;) {
        if (iNode->data == value) {
            iNode = iNode->next;
            removeAt(i);
        }
        else {
            ++i;
            iNode = iNode->next;
        }
    }
}

header void LinkedList<T>::insert(T value, size_t index) {
    if (index > m_size || index < 0) throw std::out_of_range("index_out_of_range");
    ++m_size;
    Node* nodeToAdd = new Node(value);
    if (index == 0) {
        nodeToAdd->next = this->first;
        this->first = nodeToAdd;
        return;
    }
    Node* iNode = this->first;
    for (int i = 0;i < index - 1;++i) {
        iNode = iNode->next;
    }
    nodeToAdd->next = iNode->next;
    iNode->next = nodeToAdd;
}

header void LinkedList<T>::replaceAt(T value, size_t index) {
    if (index >= m_size || index < 0) throw std::out_of_range("index_out_of_range");
    Node* iNode = this->first;
    for (int i = 0;i < index;++i) {
        iNode = iNode->next;
    }
    iNode->data = value;
}


header void LinkedList<T>::push_back(T value) {
    if (m_size == 0) {
        this->first = new Node(value);
        ++m_size;
        return;
    }
    Node* iNode = this->first;
    while (iNode->next != nullptr) {
        iNode = iNode->next;
    }
    iNode->next = new Node(value);
    ++m_size;
}


header void LinkedList<T>::push_front(T value) {
    Node* iNode = new Node(value);
    iNode->next = this->first;
    this->first = iNode;
    ++m_size;
}


header T LinkedList<T>::pop_back() {
    if (m_size == 0) throw std::invalid_argument("nothing_to_remove");
    T temp;
    if (m_size == 1) {
        temp = this->first->data;
        delete this->first;
        --m_size;
        return temp;
    }
    Node* iNode = this->first;
    for (int i = 0;i < (m_size - 2);++i) {
        iNode = iNode->next;
    }
    Node* aux = iNode->next;
    temp = aux->data;
    iNode->next = nullptr;
    delete aux;
    --m_size;
    return temp;
}


header T LinkedList<T>::pop_front() {
    if (m_size == 0) throw std::invalid_argument("nothing_to_remove");
    --m_size;
    T temp = this->first->data;
    Node* aux = this->first;
    this->first = this->first->next;
    delete aux;
    return temp;
}


header bool LinkedList<T>::equals(LinkedList& other) {
    if (this->empty() && other.empty()) return true;
    if(this->empty() xor other.empty()) return false;
    if (this->m_size != other.m_size) return false;
    Node* iNode = this->first;
    Node* otherNode = other.getNode(0);
    for (int i = 0;i < m_size;++i) {
        if (iNode->data != otherNode->data) {
            return false;
        }
        iNode = iNode->next;
        otherNode = otherNode->next;
    }
    return true;
}


header void LinkedList<T>::concat(LinkedList& other){
    if(other.empty()) return;
    Node* otherNode = other.getNode(0);
    if(empty()){
        this->push_front(otherNode->data);
        otherNode = otherNode->next;
    }
    Node* iNode = this->getNode(m_size-1);
    while (iNode->next != nullptr)
    {
        iNode = iNode->next;
    }
    m_size += other.size();
    for(int i=0;i<other.size();++i){
        iNode->next = new Node(otherNode->data);
        iNode = iNode->next;
        otherNode = otherNode->next;
    }    
}

#undef header
#endif