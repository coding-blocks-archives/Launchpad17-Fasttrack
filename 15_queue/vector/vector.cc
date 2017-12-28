// vector.cc --> functionality
#include "vector.h"

// template <typename T>
Vector::Vector() {
    capacity = 5;
    container = new T[capacity];
    size = 0;
}

// template <typename T>
bool Vector::empty() const {
    return size == 0;
}

// template <typename T>
void Vector::clear() {
    for (int i = 0; i < capacity; ++i) {
        container[i] = 0;
    }
}

// template <typename T>
void Vector::push_back(const T& d) {
    if (size == capacity) {
        resize(2 * capacity);
    }
    container[size] = d;
    ++size;
}

// template <typename T>
void Vector::pop_back() {
    if (empty() == false) --size;
}

// template <typename T>
int Vector::sizeFunc() const{
    return size;
}

// template <typename T>
T Vector::at(int idx) const{
    if (idx < size) {
        return container[idx];
    }
    // return -1;
}

// template <typename T>
void Vector::resize(int newSize) {
    T* tmp = new T[newSize];

    // copy(tmp, container);
    for (int i = 0; i < size; ++i) {
        tmp[i] = container[i];
    }

    delete container;
    container = tmp;
    capacity = newSize;
}

// template <typename T>
Vector::~Vector(){
    delete [] container;
}
