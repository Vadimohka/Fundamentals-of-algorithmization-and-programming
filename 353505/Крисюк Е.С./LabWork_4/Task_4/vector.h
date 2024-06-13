#ifndef VECTOR_H
#define VECTOR_H

#include "iterator.h"

template <typename T>

class Vector
{

private:

    T* array = nullptr;
    size_t vector_size = 0;
    size_t vector_capacity = 0;

    using iterator = Iterator<T>;
    using riterator = RIterator<T>;
    using citerator = Iterator<const T>;


public:

    Vector();
    explicit Vector(size_t n);

    ~Vector();


    T &operator[](size_t);

    void assign(size_t, T);
    T &at(size_t);
    size_t capacity();
    void clear();
    bool empty();
    T& front();
    T& back();
    size_t max_size();
    void pop_back(T);
    void push_back(T);
    void reserve(size_t);
    void resize(size_t);
    size_t size();
    void swap(Vector<T> &);
    T &data();


    iterator begin();
    iterator end();

    citerator cbegin();

    riterator rbegin();
    riterator rend();

    template<typename ... Args>
    void emplace(citerator, Args ... args);

    template<typename ... Args>
    void emplace_back(Args &&... args);

    void erase(iterator tmp);


    template<typename ... Args>

    void insert(citerator, Args ... args);


};

#endif // VECTOR_H
