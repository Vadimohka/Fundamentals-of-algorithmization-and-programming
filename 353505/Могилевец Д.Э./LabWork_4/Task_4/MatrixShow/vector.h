#ifndef VECTOR_H
#define VECTOR_H

#include <initializer_list>
#include "iterator.h"

template<typename T>
class Vector {
    using b_iterator = iterator<T>;
    using r_iterator = reverse_iterator<T>;
    using c_iterator = iterator<const T>;
private:
    T *arr_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    Vector();

    explicit Vector(size_t n);

    Vector(Vector<T> const &tmp_);

    Vector(std::initializer_list<T> list_);

    ~Vector();

    T &operator[](size_t n_) const;

    template<typename ... Args>
    void emplace(c_iterator pos, Args &&... args);

    template<typename ... Args>
    void emplace_back(Args &&... args);

    void insert(c_iterator pos_, T const &tmp_);

    void insert(c_iterator pos_, T &&tmp_);

    void push_back(T tmp_);

    void assign(size_t n, T tmp_);

    void assign(c_iterator beg, c_iterator end);

    void clear();

    void erase(Vector<T>::b_iterator tmp);

    void erase(Vector<T>::b_iterator beg, Vector<T>::b_iterator end);

    void pop_back();
    T &front();

    T &back();

    T &at(size_t pos_);

    T *data();
    size_t capacity();

    size_t size();

    size_t max_size();

    void resize(size_t size_, T tmp_ = T());

    void reserve(size_t size_);

    bool empty();

    void swap(Vector<T> &toSwap);

    b_iterator begin();

    b_iterator end();

    r_iterator rbegin();

    r_iterator rend();

    c_iterator cbegin() const;

    c_iterator cend() const;
};

#endif // VECTOR_H
