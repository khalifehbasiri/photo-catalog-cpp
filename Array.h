#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>
#include <string>
#include "defs.h"

using namespace std;

template<typename T>
class Array {
public:
    // Constructor
    Array();

    // Destructor
    ~Array();

    // Other
    void add(const T&);
    void remove(const T&);
    int size() const;
    bool isFull() const;
    void clear();

    // Operator overloads
    T& operator[](int index);
    const T& operator[](int index) const;
    Array& operator+=(const T&);
    Array& operator-=(const T&);

private:
    int numElements;
    T* elements;
};

template<typename T>
Array<T>::Array() {
    elements = new T[MAX_ARRAY];
    numElements = 0;
}

template<typename T>
Array<T>::~Array() {
    delete[] elements;
}

template<typename T>
void Array<T>::add(const T& t) {
    if (numElements >= MAX_ARRAY) return;
    elements[numElements++] = t;
}

template<typename T>
void Array<T>::remove(const T& t) {
    int index = 0;
    while (index < numElements) {
        if (t == elements[index]) {
            --numElements;
            break;
        }
        ++index;
    }

    while (index < numElements) {
        elements[index] = elements[index + 1];
        ++index;
    }
}

template<typename T>
int Array<T>::size() const {
    return numElements;
}

template<typename T>
bool Array<T>::isFull() const {
    return numElements >= MAX_ARRAY;
}

template<typename T>
void Array<T>::clear() {
    numElements = 0;
}

template<typename T>
T& Array<T>::operator[](int index) {
    if (index < 0 || index >= numElements) {
        cerr << "Array index out of bounds" << endl;
        exit(1);
    }
    return elements[index];
}

template<typename T>
const T& Array<T>::operator[](int index) const {
    if (index < 0 || index >= numElements) {
        cerr << "Array index out of bounds" << endl;
        exit(1);
    }
    return elements[index];
}

template<typename T>
Array<T>& Array<T>::operator+=(const T& t) {
    add(t);
    return *this;
}

template<typename T>
Array<T>& Array<T>::operator-=(const T& t) {
    remove(t);
    return *this;
}

#endif
