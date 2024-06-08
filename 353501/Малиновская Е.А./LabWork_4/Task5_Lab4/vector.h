#ifndef VECTOR_H
#define VECTOR_H

#include "iterator.h"
#include <algorithm>
#include <initializer_list>
#include <climits>
#include <stdexcept>

template <typename T>
class Vector
{
    using iterator = Iterator<T>;
    using riterator = Rev_Iterator<T>;
    using citerator = Iterator<const T>;
    using criterator = Rev_Iterator<const T>;
private:
    T* data_ = nullptr;
    size_t size_ = 0;
    size_t reserved_ = 0;

public:
    Vector();
    explicit Vector<T> (size_t n);
    Vector (Vector<T> const &newV);
    Vector (std::initializer_list<T> list_);
    ~Vector();

    size_t capacity();
    size_t size();
    size_t max_size();
    bool empty();
    void clear();

    void insert(size_t pos, const T& t);
    template<typename ... Args>
    void emplace(size_t pos, Args &&... args);
    template<typename ... Args>
    void emplace_back(Args &&... args);

    void assign(size_t n, T t);
    void erase(Vector<T>::iterator tmp);
    void erase(Vector<T>::iterator beg, Vector<T>::iterator end);

    T &operator[](size_t n) const;
    void reserve(size_t size);
    void resize(size_t size, T temp = T());
    void push_back(T temp);
    void pop_back();

    void swap(Vector<T> &v);


    T &front();
    T &back();
    T &at(size_t pos_);
    T *data();

    iterator begin();
    iterator end();
    riterator rbegin();
    riterator rend();
    citerator cbegin() const;
    citerator cend() const;
};


template<typename T>
Vector<T>::Vector()
{
    data_ = nullptr;
    size_= 0;
    reserved_ = 0;
}

template<typename T>
Vector<T>::Vector(const Vector<T> &newV)
{
    size_ = newV.size_;
    reserved_ = newV.reserved_;
    data_ = new T[size_];
    for (size_t i = 0; i < size_; i++) {
        new(data_ + i) T(newV.data_[i]);
    }

}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> list_) : size_(list_.size()), reserved_(list_.size())
{
    data_ = new T[size_];
    size_t i = 0;
    for (const T& element : list_) {
        data_[i++] = element;
    }
}


template<typename T>
Vector<T>::~Vector()
{
    for (size_t i = 0; i < size_; i++) {
        (data_ + i)->~T();
    }
    delete[] data_;
    data_ = nullptr;
    reserved_ = 0;
    size_ = 0;
}

template<typename T>
size_t Vector<T>::capacity()
{
    return reserved_;
}

template<typename T>
size_t Vector<T>::size()
{
    return size_;
}

template<typename T>
size_t Vector<T>::max_size()
{
    return LLONG_MAX / sizeof(T);
}

template<typename T>
void Vector<T>::insert(size_t pos, const T &t)
{
    reserve(size_ + 1);
    size_++;

    for(auto i = size_ - 1; i > pos; i--){
        data_[i] = data_[i - 1];
    }
    data_[pos] = t;
}

template<typename T>
void Vector<T>::assign(size_t n, T t)
{
    clear();
    resize(n, t);
}

template<typename T>
void Vector<T>::erase(iterator tmp)
{
    erase(tmp, tmp);
}

template<typename T>
void Vector<T>::erase(iterator beg, iterator end)
{
    int it1 = beg.base() - data_;
    int it2 = end.base() - data_;
    for (auto i = it1; i <= it2; i++) {
        (data_ + i)->~T();
        new(data_ + i) T(data_[i + 1]);
    }

    size_ = size_ - (it2 - it1);

}

template<typename T>
T &Vector<T>::operator[](size_t n) const
{
    return data_[n];
}

template<typename T>
Vector<T>::Vector(size_t n) {
    reserve(n);
    for (size_t i = 0; i < n; i++) {
        new(data_ + i) T();
    }
}

template<typename T>
void Vector<T>::reserve(size_t size)
{
    if (size <= reserved_)
        return;

    T *newData = new T[size];
    auto dataMaxInd = std::min(size, size_);
    for(int i = 0; i < dataMaxInd; ++i){
        newData[i] = data_[i];
    }

    delete [] data_;
    data_ = newData;
    size_ = dataMaxInd;
    reserved_ = size;
}

template<typename T>
void Vector<T>::resize(size_t size, T temp) {
    if (size > reserved_)
        reserve(size);

    for (size_t i = size_; i < size; i++) {
        new(data_ + i) T(temp);
    }
    for (size_t i = size; i < size_; i++) {
        (data_ + i)->~T();
    }
    size_ = size;
}

template<typename T>
void Vector<T>::push_back(T temp)
{
    if (size_ >= reserved_)
    {
        reserve(size_ + 1);
    }
    new (data_ + size_) T(temp);
    ++size_;
}

template<typename T>
void Vector<T>::pop_back()
{
    if(size_ == 0){
        return;
    }
    (data_ + size_ - 1)->~T();
    size_--;
}

template<typename T>
bool Vector<T>::empty()
{
    return size_ == 0;
}

template<typename T>
void Vector<T>::clear()
{
    resize(0);
}


template<typename T>
template<typename... Types>
void Vector<T>::emplace(size_t pos, Types &&... args){
    T temp(args...);
    insert(pos, temp);
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(Args &&... args) {
    T tmp(args...);
    push_back(tmp);
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return iterator(data_);
}
template<typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return iterator(data_ + size_);
}

template<typename T>
typename Vector<T>::citerator Vector<T>::cbegin() const {
    return citerator(data_);
}

template<typename T>
typename Vector<T>::citerator Vector<T>::cend() const {
    return citerator(data_ + size_);
}

template<typename T>
typename Vector<T>::riterator Vector<T>::rbegin() {
    return riterator(data_ + size_ - 1);
}

template<typename T>
typename Vector<T>::riterator Vector<T>::rend() {
    return riterator(data_ - 1);
}


template<typename T>
T &Vector<T>::front() {
    return data_[0];
}

template<typename T>
T &Vector<T>::back() {
    return data_[size_ - 1];
}

template<typename T>
T &Vector<T>::at(size_t pos_) {
    if (pos_ > size_) throw std::out_of_range("");
    try {
        return data_[pos_];
    } catch (...) {
        throw std::out_of_range("");
    }
}

template<typename T>
T *Vector<T>::data() {
    return data_ ;
}

template<typename T>
void Vector<T>::swap(Vector<T> &v)
{
    std::swap(data_, v.data_);
    std::swap(size_, v.size_);
    std::swap(reserved_, v.reserved_);
}
#endif // VECTOR_H
