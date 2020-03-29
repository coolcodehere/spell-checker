#include "ArrayList.h"
#include <iostream>
using namespace std;

// v-- Memory Management --v

template <class T>
ArrayList<T>::ArrayList() {
    capacity = 5;
    size = 0;
    arr = new T[capacity];
}


template <class T>
ArrayList<T>::ArrayList(const ArrayList& other) {
    capacity = other.capacity;
    size = other.size;

    for (long i = 0; i < capacity; i++) {
        arr[i] = other.arr[i];
    }
}


template <class T>
ArrayList<T>& ArrayList<T>::operator= (const ArrayList& other) {
    capacity = other.capacity;
    size = other.size;
    arr = other.arr;

    return *this;
}

// v-- Public Methods --v

template <class T>
void ArrayList<T>::resize(long newCapacity) {
    T* tempArr = new T[newCapacity];
    
    for (long i = 0; i < capacity; i++){
        tempArr[i] = arr[i];
    }

    delete[] arr; 
    arr = tempArr; 
    capacity = newCapacity; 
}

template class ArrayList<int>;
template class ArrayList<string>;
template class ArrayList<bool>;