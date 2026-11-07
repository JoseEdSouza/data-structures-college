#pragma once 
#include <iostream>

template <typename T>
class ArrayDoPaeDuplo {
    private:
        size_t m_size;
        size_t capacity;
        T* data;
        size_t right_index;
        size_t left_index;
        size_t pivot;

        void resize(int type = 1);

        void right_shift();
        void left_shift();

    public:
        ArrayDoPaeDuplo();
        ArrayDoPaeDuplo(size_t n);
        ArrayDoPaeDuplo(std::initializer_list<T> initial);
        ~ArrayDoPaeDuplo();

        size_t size();
        const size_t size() const;
        bool empty();

        T & operator[](size_t index);
        const T& operator[](size_t index) const;
        T& at(size_t index);

        void replaceAt(size_t index, T value);

        void push_back(T value);
        T pop_back();
        void push_front(T value);
        T pop_front();

        void insert(size_t index, T value);
        void removeAt(size_t index);
        void removeAll(T value);

        void print();
        void printReverse();

        bool equals(ArrayDoPaeDuplo& other);

        void concat(ArrayDoPaeDuplo& other);
        void printAll() {
            for (int i = 0;i < capacity;++i) {
                std::cout << data[i] << " ";
            }
            std::cout << "\n";
        }
};

