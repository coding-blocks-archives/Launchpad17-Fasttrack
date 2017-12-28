// vector.h --> contract
#ifndef VECTOR_H_
#define VECTOR_H_

template <typename T>
class Vector{
    T* container;
    int size;
    int capacity;
public:
    Vector();
    void resize(int newSize);
    void clear();
    void push_back(T);
    void pop_back();
    bool empty();
    int sizeFunc();
    T at(int idx);
    ~Vector();
};
#endif