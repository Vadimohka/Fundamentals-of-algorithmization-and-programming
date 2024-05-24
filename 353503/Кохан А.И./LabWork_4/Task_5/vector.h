#ifndef VECTOR_H
#define VECTOR_H

#include "iterator.h"

template<typename T>
class Vector
{
    T *array = nullptr;
    size_t size_{0};
    size_t capacity_{0};
    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T>;

public:
    Vector();
    explicit Vector(size_t n_size);
    ~Vector();

    void assign(size_t n_size, T value);
    void assign(const_iterator begin, const_iterator end);
    T &at(size_t index);
    T &back();
    size_t capacity() const;
    void clear();
    T *data();

    template<typename... Args>
    void emplace(size_t pos, Args &&...args);

    template<typename... Args>
    void emplace_back(Args &&...args);

    bool empty();
    void erase(Vector<T>::iterator value);
    void erase(Vector<T>::iterator begin, Vector<T>::iterator end);
    T &front();
    void insert(size_t pos, const T &value);
    size_t max_size();
    void pop_back();
    void push_back(const T &value);
    void reserve(size_t n_size);
    void resize(size_t n_size, const T &value = T());
    size_t size() const;
    void swap(Vector<T> &value);
    const T &operator[](size_t index) const;
    T &operator[](size_t index);

    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
};

#endif // VECTOR_H
