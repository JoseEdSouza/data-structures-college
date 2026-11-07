#pragma once
#include <iostream>
#include "ArrayDoPaeDuplo.hpp"
#define header template<typename T>

header ArrayDoPaeDuplo<T>::ArrayDoPaeDuplo() {
    m_size = 0;
    capacity = 16;
    pivot = capacity / 2;
    right_index = pivot;
    left_index = pivot;
    this->data = new T[capacity];
}

header ArrayDoPaeDuplo<T>::ArrayDoPaeDuplo(size_t n) {
    m_size = 0;
    capacity = n;
    pivot = capacity / 2;
    right_index = pivot;
    left_index = pivot;
    this->data = new T[capacity];
}

header ArrayDoPaeDuplo<T>::ArrayDoPaeDuplo(std::initializer_list<T> initial) {
    this->m_size = initial.size();
    this->capacity = this->m_size;
    this->pivot = capacity / 2;
    this->left_index = 0;
    this->right_index = m_size - 1;
    this->data = new T[capacity];
    int i = 0;
    for (T element : initial) {
        data[left_index + i] = element;
        ++i;
    }
}

header ArrayDoPaeDuplo<T>::~ArrayDoPaeDuplo() {
    delete[] data;
}

header void ArrayDoPaeDuplo<T>::resize(int type) {
    if (type != 1 && type != 2) throw std::invalid_argument("valid_types_are_1_and_2");
    size_t new_left_index;
    size_t new_right_index;

    if (type == 1) {
        pivot = capacity;
        new_left_index = pivot - (m_size / 2);
        new_right_index = new_left_index + m_size - 1;
        capacity = capacity * 2;
    }
    else {
        pivot = m_size / 2;
        new_left_index = 0;
        new_right_index = m_size - 1;
        capacity = m_size;
    }

    T* newData = new T[capacity];
    for (int i = 0; i < m_size; ++i) {
        newData[i + new_left_index] = data[left_index + i];
    }
    delete[] this->data;
    data = newData;
    left_index = new_left_index;
    right_index = new_right_index;
}

header void ArrayDoPaeDuplo<T>::right_shift() {
    if (right_index >= capacity - 1) return;
    for (int j = right_index + 1;j >= left_index;--j) {
        data[j] = data[j - 1];
    }
    ++left_index;
    ++right_index;
}

header void ArrayDoPaeDuplo<T>::left_shift() {
    if (left_index == 0) return;
    for (size_t j = left_index - 1; j <= right_index; ++j) {
        data[j] = data[j + 1];
    }
    --right_index;
    --left_index;
}

header size_t ArrayDoPaeDuplo<T>::size() {
    return m_size;
}

header const size_t ArrayDoPaeDuplo<T>::size() const {
    return m_size;
}

header bool ArrayDoPaeDuplo<T>::empty() {
    return (m_size == 0);
}

header T& ArrayDoPaeDuplo<T>::operator[](size_t index) {
    if (index >= m_size || index < 0) throw std::out_of_range("index_out_of_range");
    return data[left_index + index];
}

header const T& ArrayDoPaeDuplo<T>::operator[](size_t index) const {
    if (index >= m_size || index < 0) throw std::out_of_range("index_out_of_range");
    return data[left_index + index];
}

header T& ArrayDoPaeDuplo<T>::at(size_t index) {
    return this->operator[](index);
}

header void ArrayDoPaeDuplo<T>::replaceAt(size_t index, T value) {
    if (index >= m_size || index < 0) throw std::out_of_range("index_out_of_range");
    data[left_index + index] = value;
}

header void ArrayDoPaeDuplo<T>::push_back(T value) {
    if (m_size == capacity) resize();
    if (right_index == capacity - 1) left_shift();
    if (m_size == 0) data[right_index] = value;
    else data[++right_index] = value;
    ++m_size;
    if (((left_index)) > (capacity - right_index))
        left_shift();
}

header T ArrayDoPaeDuplo<T>::pop_back() {
    T temp = data[right_index];
    --m_size;
    --right_index;
    if (m_size == capacity / 2) resize(2);
    else if (abs((capacity - right_index) - left_index) > 1) left_shift();
    return temp;
}

header void ArrayDoPaeDuplo<T>::push_front(T value) {
    if (m_size == capacity) resize();
    if (left_index == 0) right_shift();
    if (m_size == 0) data[left_index] = value;
    data[--left_index] = value;
    ++m_size;
    if ((left_index) < (capacity - right_index)) right_shift();
}

header T ArrayDoPaeDuplo<T>::pop_front() {
    T temp = data[left_index];
    --m_size;
    ++left_index;
    if (m_size == capacity / 2) resize(2);
    else if (abs((capacity - right_index) - left_index) > 1) right_shift();
    return temp;
}

header void ArrayDoPaeDuplo<T>::insert(size_t index, T value) {
    if (index > m_size || index < 0) throw std::out_of_range("index_out_of_range");
    if (m_size == capacity) resize();
    for (int i = right_index + 1;i > index + left_index;--i) {
        data[i] = data[i - 1];
    }
    data[index] = value;
    ++m_size;
    ++right_index;
    if (abs((capacity - right_index) - left_index) > 1) {
        if (pivot - index > 0)
            left_shift();
        else
            right_shift();
    }
}

header void ArrayDoPaeDuplo<T>::removeAt(size_t index) {
    if (index >= m_size || index < 0) throw std::out_of_range("index_out_of_range");
    if (empty()) throw std::invalid_argument("nothing_to_remove");

    for (int i = index + left_index;i <= right_index;++i) {
        data[i] = data[i + 1];
    }
    --m_size;
    --right_index;
    if (m_size == (capacity / 2)) resize(2);
    else if (abs((capacity - right_index) - left_index) > 1) {
        if (pivot - index > 0)
            left_shift();
        else
            right_shift();
    }
}

header void ArrayDoPaeDuplo<T>::removeAll(T element) {
    if (empty()) return;
    for (int i = 0;i < m_size;) {
        if (at(i) == element) {
            removeAt(i);
            if(empty()) return;
        }
        else ++i;
    }
}

header bool ArrayDoPaeDuplo<T>::equals(ArrayDoPaeDuplo<T>& other) {
    if (empty() && other.empty()) return true;
    if (empty() xor other.empty()) return false;
    if (size() != other.size()) return false;
    for (int i = 0;i < m_size;++i) {
        if (this->at(i) != other.at(i)) return false;
    }
    return true;
}


header void ArrayDoPaeDuplo<T>::concat(ArrayDoPaeDuplo<T>& other) {
    if (other.empty()) return;
    for (int i = 0;i < other.size();++i) {
        push_back(other.at(i));
    }
}

header void ArrayDoPaeDuplo<T>::print() {
    if(empty()) return;
    for (int i = 0;i < m_size;++i) {
        std::cout << at(i) << " ";
    }
    std::cout << "\n";
}

header void ArrayDoPaeDuplo<T>::printReverse() {
    if(empty()) return;
    for (int i = m_size - 1;i >= 0;--i) {
        std::cout << at(i) << " ";
    }
    std::cout << "\n";
}

#undef header
