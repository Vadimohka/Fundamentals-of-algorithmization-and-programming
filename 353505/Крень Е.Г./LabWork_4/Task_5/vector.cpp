#include <stdexcept>
#include "vector.h"
#include "pair.h"
#include <initializer_list>

template<typename T>
Vector<T>::Vector() {
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template<typename T>
Vector<T>::Vector(size_t n) {
    reserve(n);
    for (size_t i = 0; i < n; i++) {
        new(arr_ + i) T();
    }
}

template<typename T>
Vector<T>::Vector(Vector<T> const &tmp_) {
    size_ = tmp_.size_;
    capacity_ = tmp_.capacity_;
    arr_ = reinterpret_cast<T*>(new int8_t[size_ * sizeof(T)]);
    for (size_t i = 0; i < size_; i++) {
        new (arr_ + i) T(tmp_[i]);
    }
}


template<typename T>
Vector<T>::Vector(std::initializer_list<T> l) :
    size_(l.size()),
    capacity_(l.size())
{
    arr_ = reinterpret_cast<T *>(new int8_t[size_ * sizeof(T)]);
    auto listIt = l.begin();
    for (size_t i = 0; i < size_; i++, listIt++) {
        T tmp = *listIt;
        new(arr_ + i) T(std::move(tmp));
    }
}

template<typename T>
Vector<T>::~Vector() {
    for (size_t i = 0; i < size_; i++) {
        (arr_ + i)->~T();
    }
    // delete[] reinterpret_cast<int8_t *>(arr_);
    arr_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}

template<typename T>
T &Vector<T>::operator[](size_t n_) const {
    return arr_[n_];
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace(Vector::c_iterator pos, Args &&... args) {
    T tmp(args...);
    insert(pos, tmp);
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(Args &&... args) {
    T tmp(args...);
    push_back(tmp);
}

template<typename T>
void Vector<T>::insert(Vector::c_iterator pos_, T const &tmp_) {
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
void Vector<T>::insert(Vector::c_iterator pos_, T &&tmp_) {
    size_t pos = pos_.base() - arr_;
    if (size_ >= capacity_) reserve(2 * size_ + 1);
    for (size_t i = size_; i > pos; i--) {
        new(arr_ + i) T(arr_[i - 1]);
        (arr_ + i - 1)->~T();
    }
    new(arr_ + pos) T(tmp_);
    size_++;
}

template<typename T>
void Vector<T>::push_back(T tmp_) {
    if (size_ >= capacity_) reserve(2 * size_ + 1);
    new(arr_ + size_) T(tmp_);
    size_++;
}

template<typename T>
void Vector<T>::assign(size_t n, T tmp_) {
    clear();
    resize(n, tmp_);
}

template<typename T>
void Vector<T>::assign(Vector::c_iterator beg, Vector::c_iterator end) {
    clear();
    int sz = end.base() - beg.base();
    resize(sz);
    for (auto i = 0; i < sz; i++) {
        new(arr_ + i) T(*(beg + i));
    }
}

template<typename T>
void Vector<T>::clear() {
    resize(0);
}

template<typename T>
void Vector<T>::erase(Vector::b_iterator tmp) {
    erase(tmp, tmp + 1);
}

template<typename T>
void Vector<T>::erase(Vector<T>::b_iterator beg, Vector<T>::b_iterator end) {
    int i1 = beg.base() - arr_;
    int i2 = end.base() - arr_;
    for (auto i = i1; i <= i2; i++) {
        (arr_ + i)->~T();
        new(arr_ + i) T(arr_[i + 1]);
    }
    size_ = size_ - (i2 - i1);
}

template<typename T>
void Vector<T>::pop_back() {
    if (!empty()) (arr_ + size_ - 1)->~T();
    size_--;
}

template<typename T>
T &Vector<T>::front() {
    return arr_[0];
}

template<typename T>
T &Vector<T>::back() {
    return arr_[size_ - 1];
}

template<typename T>
T &Vector<T>::at(size_t pos_) {
    if (pos_ > size_) throw std::out_of_range("");
    try {
        return arr_[pos_];
    } catch (...) {
        throw std::out_of_range("");
    }
}

template<typename T>
T *Vector<T>::data() {
    return arr_ + 0;
}

template<typename T>
size_t Vector<T>::capacity() {
    return capacity_;
}

template<typename T>
size_t Vector<T>::size() {
    return size_;
}

template<typename T>
size_t Vector<T>::max_size() {
    return capacity_ / sizeof(T);
}

template<typename T>
void Vector<T>::resize(size_t n_size_, T tmp_) {
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
void Vector<T>::reserve(size_t n_size_) {
    if (n_size_ <= capacity_) return;
    T *tmp_ = reinterpret_cast<T *>(new int8_t[n_size_ * sizeof(T)]);
    for (size_t i = 0; i < size_; i++) {
        new(tmp_ + i) T(arr_[i]);
        (arr_ + i)->~T();
    }
    delete[]reinterpret_cast<int8_t *>(arr_);
    arr_ = tmp_;
    capacity_ = n_size_;
}

template<typename T>
bool Vector<T>::empty() {
    return size_ == 0;
}

template<typename T>
void Vector<T>::swap(Vector<T> &toSwap) {
    std::swap(arr_, toSwap.arr_);
    std::swap(size_, toSwap.size_);
    std::swap(capacity_, toSwap.capacity_);
}

template<typename T>
typename Vector<T>::b_iterator Vector<T>::begin() {
    return b_iterator(arr_);
}

template<typename T>
typename Vector<T>::b_iterator Vector<T>::end() {
    return b_iterator(arr_ + size_);
}

template<typename T>
typename Vector<T>::c_iterator Vector<T>::cbegin() const {
    return c_iterator(arr_);
}

template<typename T>
typename Vector<T>::c_iterator Vector<T>::cend() const {
    return c_iterator(arr_ + size_);
}

template<typename T>
typename Vector<T>::r_iterator Vector<T>::rbegin() {
    return r_iterator(arr_ + size_);
}

template<typename T>
typename Vector<T>::r_iterator Vector<T>::rend() {
    return r_iterator(arr_);
}


template class Vector<Vector<Vector<pair<pair<std::string, std::string>, pair<std::string, std::string>>>>>;
template class Vector<Vector<pair<pair<std::string, std::string>, pair<std::string, std::string>>>>;
template class Vector<int>;
template class Vector<pair<Vector<int>, Vector<pair<int, double>>>>;
template class Vector<pair<int, double>>;
