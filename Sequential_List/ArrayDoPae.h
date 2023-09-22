#pragma once
#include <iostream>

template<typename T>
class ArrayDoPae {
private:
    T* data;
    size_t capacity;
    size_t size_of;

    /**
    * The function implements the insertion sort algorithm to sort an array in ascending order.
    * 
    * @param end The parameter "end" represents the index of the last element in the array that needs to
    * be sorted.
    * 
    * @return void, which means it does not return any value.
    */
    void insertion_sort(size_t end);
    /**
    * The function resizes an array to a specified size while preserving the existing elements.
    * 
    * @param n The parameter `n` represents the new size of the array.
    */
    void resize(size_t n);

public:
    ArrayDoPae();
    /**
    * The above function is a copy constructor for the ArrayDoPae class in C++, which creates a new object
    * by copying the contents of another object.
    * 
    * @param other The "other" parameter is a reference to an object of the same type as the current
    * object. It is used to initialize the current object with the values from the "other" object.
    */
    ArrayDoPae(ArrayDoPae& other);
    /**
    * The function initializes an ArrayDoPae object with the elements from an initializer list.
    * 
    * @param initial The "initial" parameter is an initializer list of type T. It is used to initialize
    * the ArrayDoPae object with the elements provided in the initializer list.
    */
    ArrayDoPae(std::initializer_list<T> initial);
    ~ArrayDoPae();

    /**
    * The function returns the size of the ArrayDoPae object.
    * 
    * @return The size of the array is being returned.
    */
    size_t size();
    /**
    * The function returns the size of the ArrayDoPae object.
    * 
    * @return The size of the array is being returned.
    */
    const size_t size() const;

    /**
    * The function returns the first element of the array if it is not empty, otherwise it returns -1.
    * 
    * @return the first element of the array, which is of type T.
    */
    T begin();
    /**
    * The function returns the first element of the array if it is not empty, otherwise it returns -1.
    * 
    * @return the first element of the array, which is of type T.
    */
    const T begin() const;

    /**
    * The function returns the last element of the array if it is not empty, otherwise it returns -1.
    * 
    * @return the last element of the array.
    */
    T end();
    /**
    * The function returns the last element of the array if it is not empty, otherwise it returns -1.
    * 
    * @return the last element of the array.
    */
    const T end() const;

    /**
    * The function checks if the array is empty by comparing the size to zero.
    * 
    * @return a boolean value, specifically the result of the comparison `size_of == 0`.
    */
    bool empty();
    /**
    * The function adds an element to an array, resizing the array if necessary.
    * 
    * @param element The "element" parameter is of type T, which means it can be any data type.
    */
    void add(T element);
    /**
    * The function removes an element from an array at a specified index and resizes the array if
    * necessary.
    * 
    * @param index The index parameter represents the position of the element that needs to be removed
    * from the array.
    */
    void remove(size_t index);
    /**
    * The function inserts an element at a specified index in an array, resizing the array if necessary.
    * 
    * @param index The index parameter represents the position at which the element should be inserted in
    * the array.
    * @param element The "element" parameter represents the value that you want to insert into the array
    * at the specified index.
    */
    void insert(size_t index, T element);
    /**
    * The function removes the first occurrence of a specified element from an array.
    * 
    * @param element The "element" parameter represents the value that you want to remove from the array.
    * 
    * @return nothing (void).
    */
    void remove_element(T element);
    /**
    * The function removes all occurrences of a specified element from an array.
    * 
    * @param element The parameter "element" is the value that you want to remove from the array.
    * 
    * @return In this code snippet, nothing is being returned. The return statement `return;` is used to
    * exit the function early if the size of the array is 0.
    */
    void remove_all(T element);
    /**
    * The function replaces an element at a specified index in an array.
    * 
    * @param index The index parameter represents the position in the array where the element should be
    * replaced.
    * @param element The "element" parameter is the value that will replace the existing element at the
    * specified index in the array.
    */
    void replace(size_t index, T element);

    /**
    * The function sorts an array using the insertion sort algorithm.
    * 
    * @return In the given code, nothing is being returned. The return statement "return;" is used to exit
    * the function early if the size_of variable is equal to 0.
    */
    void sort();
    /**
    * The function returns a constant reference to an element in an array, and throws exceptions if the
    * index is out of range or the array is empty.
    * 
    * @return The operator[] function is returning a const reference to an element of the array.
    */
    const T& operator[](size_t index) const;
    /**
    * The function overloads the [] operator to access elements in an array, checking for out of range and
    * null array conditions.
    * 
    * @return an element of type T from the data array at the specified index.
    */
    T& operator[](size_t index);

};

#include "ArrayDoPae.cpp"