#pragma once

template <typename T>
class Stack{
    private:
        T* data;
        size_t m_size;
        size_t capacity;
        void resize(size_t type = 1);
    public:
        Stack();
        ~Stack();
        
        T pop();
        void push(T value);

        bool empty();
        size_t size();
};