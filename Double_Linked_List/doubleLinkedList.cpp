#ifndef DOUBLELINKEDLIST_CPP
#define DOUBLELINKEDLIST_CPP
#include "doubleLinkedList.hpp"
#define header template <typename T>


header DoubleLinkedList<T>::DoubleLinkedList(std::initializer_list<T> initial) {
    bool flag = true;
    Node* nodeToAdd = nullptr;
    for (T element : initial) {
        nodeToAdd = { new Node(element) };
        if (flag) {
            this->first = nodeToAdd;
            this->last = nodeToAdd;
            this->first->next = this->last;
            this->last->previous = this->first;
            flag = false;
            continue;
        }
        nodeToAdd->previous = this->last;
        this->last->next = nodeToAdd;
        this->last = this->last->next;
    }
    this->first->previous = nullptr;
    this->last->next = nullptr;
    this->tam = initial.size();
};

header DoubleLinkedList<T>::~DoubleLinkedList() {
    if (this->last == nullptr) return; //nothing to delete
    Node* iterNode = this->last;
    Node* temp = nullptr;
    while (iterNode != nullptr) {
        temp = iterNode->previous;
        iterNode->previous = nullptr;
        iterNode->next = nullptr;
        delete iterNode;
        iterNode = temp;
    }
}

header size_t DoubleLinkedList<T>::size() {
    return this->tam;
}

header void DoubleLinkedList<T>::add(T element) {
    Node* nodeToAdd = { new Node(element) };
    if (tam == 0) {
        this->first = nodeToAdd;
        this->last = nodeToAdd;
        this->first->next = this->last;
        this->last->previous = this->first;
        this->first->previous = nullptr;
        this->last->next = nullptr;
        ++tam;
        return;
    }
    nodeToAdd->previous = this->last;
    nodeToAdd->next = nullptr;
    this->last->next = nodeToAdd;
    this->last = this->last->next;
    ++tam;
    return;
}

header void DoubleLinkedList<T>::remove(size_t index) {
    if (index + 1 > tam) throw std::out_of_range("index_out_of_range");
    Node* temp = nullptr;
    if (tam == 1) {
        delete this->first;
        this->last = nullptr;
        this->first = nullptr;
        --tam;
        return;
    }
    if (index == 0) {
        temp = this->first->next;
        temp->previous = nullptr;
        delete this->first;
        this->first = temp;
        --tam;
        return;
    }
    if (index + 1 == tam) {
        temp = this->last->previous;
        temp->next = nullptr;
        delete this->last;
        this->last = temp;
        --tam;
        return;
    }
    if (index <= (tam / 2)) {
        temp = this->first;
        for (int i = 0;i != index;i++) {
            temp = temp->next;
        }
    }
    else {
        temp = this->last;
        for (int i = tam - 1;i != index;--i) {
            temp = temp->previous;
        }
    }
    temp->previous->next = temp->next;
    temp->next->previous = temp->previous;
    delete temp;
    --tam;
}

header void DoubleLinkedList<T>::insert(size_t index, T element) {
    if (index + 1 > tam || index < 0) throw std::out_of_range("index_out_of_range");
    Node* nodeToInsert = { new Node(element) };
    ++tam;
    if (index == 0) {
        nodeToInsert->previous = nullptr;
        nodeToInsert->next = this->first;
        this->first->previous = nodeToInsert;
        this->first = nodeToInsert;
        return;
    }
    if (index + 1 == tam) {
        nodeToInsert->next = nullptr;
        nodeToInsert->previous = this->last;
        this->last->next = nodeToInsert;
        this->last = nodeToInsert;
        return;
    }
    Node* temp = nullptr;
    if (index <= (tam / 2)) {
        temp = this->first;
        for (int i = 0;i != index;i++) {
            temp = temp->next;
        }
    }
    else {
        temp = this->last;
        for (int i = tam - 1;i != index;--i) {
            temp = temp->previous;
        }
    }
    temp->previous->next = nodeToInsert;
    nodeToInsert->next = temp;
    nodeToInsert->previous = temp->previous;
    temp->previous = nodeToInsert;
    return;
}

header bool DoubleLinkedList<T>::contains(T element) {
    if (tam == 0) return false;
    if (this->first->data == element) return true;
    if (this->last->data == element) return true;
    Node* iterNode = this->first->next;
    while (iterNode != this->last) {
        if (iterNode->data == element)
            return true;
        else
            iterNode = iterNode->next;
    }
    return false;
}

header bool DoubleLinkedList<T>::contains(T element) const {
    if (tam == 0) return false;
    if (this->first->data == element) return true;
    if (this->last->data == element) return true;
    Node* iterNode = this->first->next;
    while (iterNode != this->last) {
        if (iterNode->data == element)
            return true;
        else
            iterNode = iterNode->next;
    }
    return false;
}

header T DoubleLinkedList<T>::operator[](int index) {
    if (index + 1 > tam || index < 0) throw std::out_of_range("index_out_of_range");
    if (index == 0) {
        return this->first->data;
    }
    if (index + 1 == tam) {
        return this->last->data;
    }

    Node* iterNode = nullptr;
    if (index <= (tam / 2)) {
        iterNode = this->first;
        int i = 0;
        while (i != index) {
            iterNode = iterNode->next;
            ++i;
        }
    }
    else {
        iterNode = this->last;
        int i = tam - 1;
        while (i != index) {
            iterNode = iterNode->previous;
            --i;
        }
    }
    return iterNode->data;
}

header const T DoubleLinkedList<T>::operator[](int index) const {
    if ((index + 1) > tam || index < 0) throw std::out_of_range("index_out_of_range");
    if (index == 0) {
        return this->first->data;
    }
    if ((index + 1) == tam) {
        return this->last->data;
    }

    Node* iterNode = this->first;
    if (index <= (tam / 2)) {
        int i = 0;
        while (i != index) {
            iterNode = iterNode->next;
            ++i;
        }
    }
    else {
        int i = tam - 1;
        while (i != index) {
            iterNode = iterNode->previous;
            --i;
        }
    }
    return iterNode->data;
}

#undef header
#endif