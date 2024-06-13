#ifndef L3T1_VECTOR_H
#define L3T1_VECTOR_H

#include <cstdint>
#include <initializer_list>
#include "iterator.h"

template<typename T>
class MyVector {
    using b_iterator = iterator<T>;
    using r_iterator = reverse_iterator<T>;
    using c_iterator = iterator<const T>;
private:
    T *arr_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    MyVector();

    explicit MyVector(size_t n);

    MyVector(MyVector<T> const &tmp_);

    MyVector(std::initializer_list<T> list_);

    ~MyVector();

    /*MyVector<T> &operator=(MyVector<T> &tmp_);*/



    T &operator[](size_t n_) const;

    // Add something

    template<typename ... Args>
    void emplace(c_iterator pos, Args &&... args);

    template<typename ... Args>
    void emplace_back(Args &&... args);

    void insert(c_iterator pos_, T const &tmp_);

    void insert(c_iterator pos_, T &&tmp_);

    void push_back(T tmp_);

    // Delete

    void assign(size_t n, T tmp_);

    void assign(c_iterator beg, c_iterator end);

    void clear();

    void erase(MyVector<T>::b_iterator tmp);

    void erase(MyVector<T>::b_iterator beg, MyVector<T>::b_iterator end);

    void pop_back();

    // links

    T &front();

    T &back();

    T &at(size_t pos_);

    T *data();

    // sizes

    size_t capacity();

    size_t size();

    size_t max_size();

    void resize(size_t size_, T tmp_ = T());

    void reserve(size_t size_);

    bool empty();

    // swap
    void swap(MyVector<T> &toSwap);

    // Iterators
    b_iterator begin()
    {
        return b_iterator(arr_);
    }
    b_iterator end()
    {
        return b_iterator(arr_ + size_);
    }
    r_iterator rbegin()
    {
          return r_iterator(arr_ + size_);
    }
    r_iterator rend()
    {
        return r_iterator(arr_);
    }
    c_iterator cbegin() const
    {
        return c_iterator(arr_);
    }

    c_iterator cend() const
    {
        return c_iterator(arr_ + size_);
    }

};


#endif
