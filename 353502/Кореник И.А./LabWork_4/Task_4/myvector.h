#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <initializer_list>
#include "myiterator.h"

template<typename T>
class myVector {
    using b_iterator = myIterator<T>;
    using r_iterator = reverse_iterator<T>;
    using c_iterator = myIterator<const T>;
private:
    T *arr_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    myVector();

    explicit myVector(size_t n);

    myVector(myVector<T> const &tmp_);

    myVector(std::initializer_list<T> list_);

    ~myVector();

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

    void erase(myVector<T>::b_iterator tmp);

    void erase(myVector<T>::b_iterator beg, myVector<T>::b_iterator end);

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

    void swap(myVector<T> &toSwap);

    b_iterator begin();

    b_iterator end();

    r_iterator rbegin();

    r_iterator rend();

    c_iterator cbegin() const;

    c_iterator cend() const;


};

#endif // MYVECTOR_H
