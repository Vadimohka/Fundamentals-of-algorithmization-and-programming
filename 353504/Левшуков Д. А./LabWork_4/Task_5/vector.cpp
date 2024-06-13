#include <stdexcept>
#include "vector.h"
#include "pair.h"

#include <memory>
#include <initializer_list>
#include<QApplication>

template<typename T>
MyVector<T>::MyVector() {
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template<typename T>
MyVector<T>::MyVector(size_t n) {
    reserve(n);
    for (int i = 0; i < n; i++) {
        new(arr_ + i) T();
    }
}

template<typename T>
MyVector<T>::MyVector(MyVector<T> const &tmp_) {
    size_ = tmp_.size_;
    capacity_ = tmp_.capacity_;
    qDebug()<<size_;
    arr_ = reinterpret_cast<T*>(new int8_t[size_ * sizeof(T)]);
    for (size_t i = 0; i < size_; i++) {
        new (arr_ + i) T(tmp_[i]);
    }
}


template<typename T>
MyVector<T>::MyVector(std::initializer_list<T> l) :
        size_(l.size()),
        capacity_(l.size()) {
    arr_ = reinterpret_cast<T *>(new int8_t[size_ * sizeof(T)]);
    auto listIt = l.begin();
    for (size_t i = 0; i < size_; i++, listIt++) {
        T tmp = *listIt;
        new(arr_ + i) T(std::move(tmp));
    }
}

template<typename T>
MyVector<T>::~MyVector() {
    for (size_t i = 0; i < size_; i++) {
        (arr_ + i)->~T();
    }
    //delete[] arr_;
    arr_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}

template<typename T>
T &MyVector<T>::operator[](size_t n_) const {
    return arr_[n_];
}

template<typename T>
template<typename... Args>
void MyVector<T>::emplace(MyVector::c_iterator pos, Args &&... args) {
    T tmp(args...);
    insert(pos, tmp);
}

template<typename T>
template<typename... Args>
void MyVector<T>::emplace_back(Args &&... args) {
    T tmp(args...);
    push_back(tmp);
}

template<typename T>
void MyVector<T>::insert(MyVector::c_iterator pos_, T const &tmp_) {
    size_t pos = (pos_).base() - arr_;
    reserve(size_ + 1);
    for (size_t i = size_; i > pos; i--) {
        new(arr_ + i) T(arr_[i - 1]);
        (arr_ + i - 1)->~T();
    }
    new(arr_ + pos) T(tmp_);
    size_++;
}

template<typename T>
void MyVector<T>::insert(MyVector::c_iterator pos_, T &&tmp_) {
    size_t pos = pos_.base() - arr_;
    reserve(size_ + 1);
    for (size_t i = size_; i > pos; i--) {
        new(arr_ + i) T(arr_[i - 1]);
        (arr_ + i - 1)->~T();
    }
    new(arr_ + pos) T(tmp_);
    size_++;
}

template<typename T>
void MyVector<T>::push_back(T tmp_) {
    if (size_ >= capacity_) reserve(2 * size_ + 1);
    new(arr_ + size_) T(tmp_);
    size_++;
    //insert(this->end(), tmp_);
}

template<typename T>
void MyVector<T>::assign(size_t n, T tmp_) {
    clear();
    resize(n, tmp_);
}

template<typename T>
void MyVector<T>::assign(MyVector::c_iterator beg, MyVector::c_iterator end) {
    clear();
    int sz = end.base() - beg.base();
    resize(sz);
    for (auto i = 0; i < sz; i++) {
        new(arr_ + i) T(*(beg + i));
    }
}

template<typename T>
void MyVector<T>::clear() {
    resize(0);
}

template<typename T>
void MyVector<T>::erase(MyVector::b_iterator tmp) {
    erase(tmp, tmp + 1);
}

template<typename T>
void MyVector<T>::erase(MyVector<T>::b_iterator beg, MyVector<T>::b_iterator end) {
    int i1 = beg.base() - arr_;
    int i2 = end.base() - arr_;
    qDebug()<<"ERASE"<<i1<<" "<<i2<<" "<<size_ - (i2 - i1);

    if(size_-(i2-i1)==0)
    {
        clear();
        return;
    }
    for (auto i = i1; i < i2; i++) {
        (arr_ + i)->~T();
        new(arr_ + i) T(arr_[i + 1]);
    }
    //qDebug()<<"ERASE"<<i1<<" "<<i2<<" "<<size_ - (i2 - i1);
    size_ = size_ - (i2 - i1);
}

template<typename T>
void MyVector<T>::pop_back() {
    if (!empty()) (arr_ + size_ - 1)->~T();
    size_--;
}

template<typename T>
T &MyVector<T>::front() {
    return arr_[0];
}

template<typename T>
T &MyVector<T>::back() {
    return arr_[size_ - 1];
}

template<typename T>
T &MyVector<T>::at(size_t pos_) {
    if (pos_ > size_) throw std::out_of_range("");
    try {
        return arr_[pos_];
    } catch (...) {
        throw std::out_of_range("");
    }
}

template<typename T>
T *MyVector<T>::data() {
    return arr_ + 0;
}

template<typename T>
size_t MyVector<T>::capacity() {
    return capacity_;
}

template<typename T>
size_t MyVector<T>::size() {
    return size_;
}

template<typename T>
size_t MyVector<T>::max_size() {
    return INT64_MAX / sizeof(T);
}

template<typename T>
void MyVector<T>::resize(size_t n_size_, T tmp_) {
    if (n_size_ > capacity_) reserve(n_size_);
    for (size_t i = size_; i < n_size_; i++) {
        new(arr_ + i) T(tmp_);
    }
    for (size_t i = n_size_; i < size_; i++) {
        (arr_ + i)->~T();
    }
    size_ = n_size_;
}

template<typename T>
void MyVector<T>::reserve(size_t n_size_) {
    if (n_size_ <= capacity_) return;
    T *tmp_ = reinterpret_cast<T *>(new int8_t[n_size_ * sizeof(T)]);
    for (int i = 0; i < size_; i++) {
        new(tmp_ + i) T(arr_[i]);
        (arr_ + i)->~T();
    }
    delete[]reinterpret_cast<int8_t *>(arr_);
    arr_ = tmp_;
    capacity_ = n_size_;
}

template<typename T>
bool MyVector<T>::empty() {
    return size_ == 0;
}

template<typename T>
void MyVector<T>::swap(MyVector<T> &toSwap) {
    std::swap(arr_, toSwap.arr_);
    std::swap(size_, toSwap.size_);
    std::swap(capacity_, toSwap.capacity_);
}




template class MyVector<MyVector<MyVector<pair<pair<std::string, std::string>, pair<std::string, std::string>>>>>;
template class MyVector<MyVector<pair<pair<std::string, std::string>, pair<std::string, std::string>>>>;
template class MyVector<int>;
template class MyVector<pair<MyVector<int>, MyVector<pair<int, double>>>>;
template class MyVector<pair<int, double>>;
