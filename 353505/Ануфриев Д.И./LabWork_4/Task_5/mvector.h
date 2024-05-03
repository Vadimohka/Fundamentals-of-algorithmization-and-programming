#ifndef MVECTOR_H
#define MVECTOR_H

#include <cstdint>
#include <initializer_list>
#include "iterator.h"
#include "pair.h"

template<typename T>
class Mvector {
    using bIterator = Iterator<T>;
    using rIterator = RIterator<T>;
    using constIterator = Iterator<const T>;
private:
    T *arr_ = nullptr;
    size_t size_ = 0;
    size_t capacity_ = 0;

public:
    Mvector();

    explicit Mvector(size_t n);

    Mvector(Mvector<T> const &tmp_);

    Mvector(std::initializer_list<T> list_);

    ~Mvector();

    /*Mvector<T> &operator=(Mvector<T> &tmp_);*/



    T &operator[](size_t n_) const;

    // Add something

    template<typename ... Args>
    void emplace(constIterator pos, Args &&... args);

    template<typename ... Args>
    void emplace_back(Args &&... args);

    void insert(constIterator pos_, T const &tmp_);

    void insert(constIterator pos_, T &&tmp_);

    void push_back(T tmp_);

    // Delete

    void assign(size_t n, T tmp_);

    void assign(constIterator beg, constIterator end);

    void clear();

    void erase(Mvector<T>::bIterator tmp);

    void erase(Mvector<T>::bIterator beg, Mvector<T>::bIterator end);

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
    void swap(Mvector<T> &toSwap);

    // Iterators
    bIterator begin();

    bIterator end();

    rIterator rbegin();

    rIterator rend();

    constIterator cbegin() const;

    constIterator cend() const;


};


#endif
