#pragma once
#include<iostream>

template<typename T>
class DoubleLinkedList {
public:
    /**The `DoubleLinkedList()` function is the constructor of the `DoubleLinkedList` class.
     * It initializes the `first` and `last` pointers to `nullptr` and sets the `tam` (size) of the list to 0. 
     * This constructor is called when a new instance of the `DoubleLinkedList` class is created.
     */
    DoubleLinkedList() {
        first = nullptr;
        last = nullptr;
        tam = 0;
    }
    /**
    * The DoubleLinkedList constructor initializes a doubly linked list with elements from an initializer
    * list.
    * 
    * @param initial The parameter "initial" is an initializer list of type T. It is used to initialize
    * the DoubleLinkedList with a list of elements of type T.
    */
    DoubleLinkedList(std::initializer_list<T>);
    /**
    * The function returns the size of the double linked list.
    * 
    * @return The size of the double linked list.
    */
    size_t size();

    /**
    * The function adds a new element to the end of a double linked list.
    * 
    * @param element The "element" parameter represents the value of the element that needs to be added to
    * the double linked list.
    * 
    * @return void, which means it does not return any value.
    */
    void add(T element);
    /**
    * The function removes a node at a specified index from a double linked list.
    * 
    * @param index The parameter "index" represents the position of the element to be removed in the
    * double linked list. It is of type "size_t", which is an unsigned integer type used to represent
    * sizes and indices.
    * 
    * @return void, which means it does not return any value.
    */
    void remove(size_t index);
    /**
    * The function `insert` inserts an element at a specified index in a double linked list.
    * 
    * @param index The index parameter represents the position at which the element should be inserted in
    * the double linked list.
    * @param element The "element" parameter represents the value of the element that you want to insert
    * into the double linked list at the specified index.
    * 
    * @return void, which means it does not return any value.
    */
    void insert(size_t index,T element);
    /**
    * The function checks if a given element is present in a double linked list.
    * 
    * @param element The "element" parameter is the value that we are checking if it exists in the double
    * linked list.
    * 
    * @return a boolean value, either true or false.
    */
    bool contains(T element);
    /**
    * The function checks if a given element is present in a double linked list.
    * 
    * @param element The "element" parameter is the value that we are checking if it exists in the double
    * linked list.
    * 
    * @return a boolean value. It returns true if the element is found in the double linked list, and
    * false otherwise.
    */
    bool contains(T element) const;
    /**
    * The function returns the element at the specified index in a double linked list.
    * 
    * @param index The index parameter represents the position of the element that we want to access in
    * the double linked list.
    * 
    * @return the data stored in the node at the specified index in the double linked list.
    */
    T operator[](int index);
    /**
    * The function returns the data at the specified index in a double linked list.
    * 
    * @param index The index parameter represents the position of the element in the double linked list
    * that you want to access. It is an integer value indicating the index of the element you want to
    * retrieve.
    * 
    * @return the data stored in the node at the specified index in the double linked list.
    */
    const T operator[](int index)const;
    /**
    * The destructor for a double linked list that deletes all nodes in the list.
    * 
    * @return In the code snippet provided, if the `last` pointer is `nullptr`, meaning the list is empty,
    * the function will return without deleting anything.
    */
    ~DoubleLinkedList();

private:
    size_t tam;
    /**The code is defining a struct named `Node` that represents a node in a double linked list.
    *It has three members: `data`, `previous`, and `next`.
    */
    typedef struct Node {
    public:
        T data;
        Node* previous;
        Node* next;
        Node(T element) {
            this->data = element;
        }
        ~Node() = default;
    }Node;
    Node* first;
    Node* last;
};

#include "doubleLinkedList.cpp"
