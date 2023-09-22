# ifndef ARRAYDOPAE_C
# define ARRAYDOPAE_C
#include "ArrayDoPae.h"
#define header template<typename T>



header void ArrayDoPae<T>::insertion_sort(size_t end) {
    if (end <= 0)
        return;

    insertion_sort(end - 1);

    T key_element = data[end - 1];
    int index_to_compare = end - 2;

    while (index_to_compare >= 0 && data[index_to_compare] > key_element) {
        data[index_to_compare + 1] = data[index_to_compare];
        --index_to_compare;
    }
    data[index_to_compare + 1] = key_element;
}


header ArrayDoPae<T>::ArrayDoPae() {
    size_of = 0;
    capacity = 8;
    data = { new T[8] };
}

header ArrayDoPae<T>::ArrayDoPae(ArrayDoPae& other) {
    this->size_of = this->capacity = other.size();
    this->data = { new T[size_of] };
    for (int i = 0; i < size_of;++i) {
        this->data[i] = other[i];
    }
}


header ArrayDoPae<T>::ArrayDoPae(std::initializer_list<T> initial) {
    if (std::empty(initial)) {
        size_of = 0;
        capacity = 8;
        data = { new T[8] };
    }
    else {
        size_of = initial.size();
        capacity = initial.size();
        data = { new T[initial.size()] };
        int i = 0;
        for (T element : initial) {
            data[i++] = element;
        }
    }
}

header ArrayDoPae<T>::~ArrayDoPae() {
    delete data;
}


header const size_t ArrayDoPae<T>::size() const {
    return size_of;
}

header size_t ArrayDoPae<T>::size() {
    return size_of;
}

header void ArrayDoPae<T>::resize(size_t n) {
    T* copy = { new T[n] };
    for (int i = 0;i < ((n > size_of) ? (size_of) : (n));++i) {
        copy[i] = data[i];
    }
    delete[] data;
    data = copy;
    capacity = n;
    if (size_of > capacity) size_of = capacity;
}

header T ArrayDoPae<T>::begin() {
    if (size_of == 0) return -1;
    return data[0];
}


header const T ArrayDoPae<T>::begin() const {
    if (size_of == 0) return -1;
    return data[0];
}


header T ArrayDoPae<T>::end() {
    if (size_of == 0) return -1;
    return data[size_of - 1];
}

header const T ArrayDoPae<T>::end() const {
    if (size_of == 0) return -1;
    return data[size_of - 1];
}

header bool ArrayDoPae<T>::empty() {
    return size_of == 0;
}


header void ArrayDoPae<T>::add(T element) {
    if (size_of == capacity) resize(capacity * 2);
    data[size_of++] = element;
}

header void ArrayDoPae<T>::remove(size_t index) {
    if (index >= size_of || index < 0) throw std::out_of_range("index_out_of_range");
    if (size_of == 0) throw std::invalid_argument("nothing_to_remove");
    for (int i = index;i < size_of;++i) {
        data[i] = data[i + 1];
    }
    --size_of;
    if (size_of <= capacity / 2) resize(capacity / 2);
}

header void ArrayDoPae<T>::insert(size_t index, T element) {
    if (index > size_of || index < 0) throw std::out_of_range("index_out_of_range");
    if (capacity == size_of) resize(capacity * 2);
    for (int i = size_of; i > index; --i) {
        data[i] = data[i - 1];
    }
    data[index] = element;
    ++size_of;
}

header void ArrayDoPae<T>::remove_element(T element) {
    if (size_of == 0) return;
    for (int i = 0;i < size_of;++i) {
        if (data[i] == element) {
            remove(i);
            return;
        }
    }
}

header void ArrayDoPae<T>::remove_all(T element) {
    if (size_of == 0) return;
    for (int i = 0;i < size_of;++i) {
        if (data[i] == element) {
            remove(i);
            --i;
        }
    }
}

header void ArrayDoPae<T>::replace(size_t index, T element) {
    if (index > size_of || index < 0) throw std::out_of_range("index_out_of_range");
    if (size_of == 0) throw std::invalid_argument("nothing_to_replace");
    data[index] = element;
}

header void ArrayDoPae<T>::sort() {
    if (size_of == 0) return;
    insertion_sort(size_of);
}

header const T& ArrayDoPae<T>::operator[](size_t index) const {
    if (index >= size_of || index < 0) throw std::out_of_range("index_out_of_range");
    if (size_of == 0) throw std::invalid_argument("null_array");
    return data[index];
}

header T& ArrayDoPae<T>::operator[](size_t index) {
    if (index >= size_of || index < 0) throw std::out_of_range("index_out_of_range");
    if (size_of == 0) throw std::invalid_argument("null_array");
    return data[index];
}



#undef header
#endif