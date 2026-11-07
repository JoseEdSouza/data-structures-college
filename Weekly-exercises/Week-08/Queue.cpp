#include <iostream>
#include "Queue.h"
#define header template <typename T>


//* defining queue's methods *//

header Queue<T>::Queue(){
    m_size = 0;
    capacity = 16;
    data = new T[capacity];
}

header Queue<T>::~Queue(){
    delete[] data;
}

header void Queue<T>::resize(size_t type){
    if (type != 1 && type != 2) throw std::invalid_argument("InvalidType:_valid_types_are_1_and_2_");
    if(type == 1)
        capacity = capacity * 2;
    else
        capacity = m_size;
    
    T* newData = new T[capacity];
    for(int i=0;i<m_size;++i){
        newData[i] = data[i];
    }
    delete[] data;
    data = newData;
}

header T Queue<T>::pop(){
    if(m_size == 0) throw std::invalid_argument("Nothing_to_remove");
    T temp = data[0];
    for(int i=0;i<m_size-1;++i){
        data[i] = data[i+1];
    }
    --m_size;
    if(m_size == capacity/2) resize(2);
    return temp;
}

header void Queue<T>::push(T value){
    if(m_size == capacity) resize(1);
    data[m_size++] = value;
}

header bool Queue<T>::empty(){
    return (m_size == 0);
}

header size_t Queue<T>::size(){
    return m_size;
}

#undef header
