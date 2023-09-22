//The code snippet provided is a C++ implementation of a linked list data structure using templates.
#pragma once
#include <iostream>

template<typename T>
class LinkedList {
private:
    /**The `struct Node` is a nested structure within the `LinkedList` class.
    *It represents a single node in the linked list.
    */
    struct Node {
        Node(T data) {
            this->data = data;
            this->next = nullptr;
        }
        ~Node() = default;
        Node* next;
        T data;
    };
    Node* first;
    size_t m_size;

    /**The `getNode` function is a private member function of the `LinkedList` class.
    *It is used to retrieve a pointer to the node at the specified index in the linked list.
    */
    Node* getNode(size_t index);
public:
    LinkedList();

    /**
    * The LinkedList constructor takes an initializer list of elements and creates a linked list with
    * those elements.
    * 
    * @param initial The parameter "initial" is an initializer list of type T. It is used to initialize
    * the LinkedList with a sequence of values.
    * 
    * @return Nothing is being returned in this constructor. It is a void function.
    */
    LinkedList(std::initializer_list<T> initial);
    
    /**
    * The destructor for the LinkedList class calls the clear() function to delete all nodes in the linked
    * list.
    */
    ~LinkedList();

    /**
    * The function checks if the linked list is empty by comparing the size of the list to zero.
    * 
    * @return a boolean value, which indicates whether the linked list is empty or not.
    */
    bool empty() const;

    /**
    * The function returns the size of the linked list.
    * 
    * @return The size of the linked list.
    */
    size_t size() const;

    /**
    * The function overloads the [] operator for a LinkedList class to access elements at a specific
    * index.
    * 
    * @return the data stored in the node at the specified index in the linked list.
    */
    T& operator[](size_t index);
    /**
    * The function overloads the subscript operator to allow accessing elements of a linked list by index.
    * 
    * @return a constant reference to the data stored in the node at the specified index in the linked
    * list.
    */
    const T& operator[](size_t index) const;

    /**
    * The function "at" returns the element at the specified index in the linked list.
    * 
    * @param index The index parameter is the position of the element that you want to access in the
    * linked list. It is of type size_t, which is an unsigned integer type used to represent the size of
    * objects in memory.
    * 
    * @return The at() function is returning the element at the specified index in the linked list.
    */
    T at(size_t index);
    /**
    * The removeAt function removes a node at a specified index from a linked list.
    * 
    * @param index The index parameter represents the position of the node that needs to be removed from
    * the linked list.
    * 
    * @return void, which means it does not return any value.
    */
    void removeAt(size_t index);
    /**
     * The function removes all occurrences of a given value from a linked list.
     * 
     * @param value The parameter "value" is the value that you want to remove from the linked list.
     */
    void removeAll(T value);
    /**
    * The function inserts a new node with a given value at a specified index in a linked list.
    * 
    * @param value The value to be inserted into the linked list at the specified index.
    * @param index The index parameter represents the position at which the new node should be inserted in
    * the linked list.
    * 
    * @return The function does not have a return type specified, so it does not explicitly return
    * anything.
    */
    void insert(T value, size_t index);
    
    void replaceAt(T value,size_t index);
    /**
    * The push_back function adds a new node with the given value to the end of the linked list.
    * 
    * @param value The "value" parameter represents the value that you want to add to the end of the
    * linked list.
    * 
    * @return In this code snippet, the `push_back` function does not explicitly return a value.
    * Therefore, it does not return anything.
    */
    void push_back(T value);
    /**
    * The push_front function adds a new node with the given value to the front of the linked list.
    * 
    * @param value The value parameter is the value that will be added to the front of the linked list.
    */
    void push_front(T value);
    /**
    * The function removes and returns the last element of a linked list.
    * 
    * @return the value of the last element in the linked list before removing it.
    */
    T pop_back();
    
    /**
    * The pop_front function removes and returns the first element of a linked list.
    * 
    * @return the data stored in the node that was removed from the front of the linked list.
    */
    T pop_front();
    
    /**
    * The function checks if two linked lists are equal by comparing their sizes and the data in each
    * node.
    * 
    * @param other The "other" parameter is a reference to another LinkedList object that we want to
    * compare with the current LinkedList object.
    * 
    * @return a boolean value, either true or false.
    */
    bool equals(LinkedList& other);
    /**
    * The `concat` function appends the elements of another LinkedList to the end of the current
    * LinkedList.
    * 
    * @param other The "other" parameter is a reference to another LinkedList object that we want to
    * concatenate with the current LinkedList object.
    * 
    * @return The `concat` function does not have a return type specified in the provided code. Therefore,
    * it does not return anything.
    */
    void concat(LinkedList& other);

    /**
    * The clear() function clears all the nodes in a linked list and sets the size to zero.
    */
    void clear();
};

#include "linkedListDoPae.cpp"