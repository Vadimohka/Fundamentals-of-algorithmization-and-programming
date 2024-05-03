#include <stdexcept>
#include "mvector.h"

#include <initializer_list>

template<typename T>
Mvector<T>::Mvector() {
    arr_ = nullptr;
    size_ = 0;
    capacity_ = 0;
}

template<typename T>
Mvector<T>::Mvector(size_t n) {
    reserve(n);
    for (int i = 0; i < n; i++) {
        new(arr_ + i) T();
    }
}

template<typename T>
Mvector<T>::Mvector(Mvector<T> const &tmp_) {
    size_ = tmp_.size_;
    capacity_ = tmp_.capacity_;
    arr_ = reinterpret_cast<T*>(new int8_t[size_ * sizeof(T)]);
    for (size_t i = 0; i < size_; i++) {
        new (arr_ + i) T(tmp_[i]);
    }
}


template<typename T>
Mvector<T>::Mvector(std::initializer_list<T> l) :
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
Mvector<T>::~Mvector() {
    for (size_t i = 0; i < size_; i++) {
        (arr_ + i)->~T();
    }
    delete[] reinterpret_cast<int8_t *>(arr_);
    arr_ = nullptr;
    capacity_ = 0;
    size_ = 0;
}

template<typename T>
T &Mvector<T>::operator[](size_t n_) const {
    return arr_[n_];
}

template<typename T>
template<typename... Args>
void Mvector<T>::emplace(Mvector::constIterator pos, Args &&... args) {
    T tmp(args...);
    insert(pos, tmp);
}

template<typename T>
template<typename... Args>
void Mvector<T>::emplace_back(Args &&... args) {
    T tmp(args...);
    push_back(tmp);
}

template<typename T>
void Mvector<T>::insert(Mvector::constIterator pos_, T const &tmp_) {
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
void Mvector<T>::insert(Mvector::constIterator pos_, T &&tmp_) {
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
void Mvector<T>::push_back(T tmp_) {
    if (size_ >= capacity_) reserve(2 * size_ + 1);
    new(arr_ + size_) T(tmp_);
    size_++;
    //insert(this->end(), tmp_);
}

template<typename T>
void Mvector<T>::assign(size_t n, T tmp_) {
    clear();
    resize(n, tmp_);
}

template<typename T>
void Mvector<T>::assign(Mvector::constIterator beg, Mvector::constIterator end) {
    clear();
    int sz = end.base() - beg.base();
    resize(sz);
    for (auto i = 0; i < sz; i++) {
        new(arr_ + i) T(*(beg + i));
    }
}

template<typename T>
void Mvector<T>::clear() {
    resize(0);
}

template<typename T>
void Mvector<T>::erase(Mvector::bIterator tmp) {
    erase(tmp, tmp + 1);
}

template<typename T>
void Mvector<T>::erase(Mvector<T>::bIterator beg, Mvector<T>::bIterator end) {
    int i1 = beg.base() - arr_;
    int i2 = end.base() - arr_;
    for (auto i = i1; i <= i2; i++) {
        (arr_ + i)->~T();
        new(arr_ + i) T(arr_[i + 1]);
    }
    size_ = size_ - (i2 - i1);
}

template<typename T>
void Mvector<T>::pop_back() {
    if (!empty()) (arr_ + size_ - 1)->~T();
    size_--;
}

template<typename T>
T &Mvector<T>::front() {
    return arr_[0];
}

template<typename T>
T &Mvector<T>::back() {
    return arr_[size_ - 1];
}

template<typename T>
T &Mvector<T>::at(size_t pos_) {
    if (pos_ > size_) throw std::out_of_range("");
    try {
        return arr_[pos_];
    } catch (...) {
        throw std::out_of_range("");
    }
}

template<typename T>
T *Mvector<T>::data() {
    return arr_ + 0;
}

template<typename T>
size_t Mvector<T>::capacity() {
    return capacity_;
}

template<typename T>
size_t Mvector<T>::size() {
    return size_;
}

template<typename T>
size_t Mvector<T>::max_size() {
    return INT64_MAX / sizeof(T);
}

template<typename T>
void Mvector<T>::resize(size_t n_size_, T tmp_) {
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
void Mvector<T>::reserve(size_t n_size_) {
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
bool Mvector<T>::empty() {
    return size_ == 0;
}

template<typename T>
void Mvector<T>::swap(Mvector<T> &toSwap) {
    std::swap(arr_, toSwap.arr_);
    std::swap(size_, toSwap.size_);
    std::swap(capacity_, toSwap.capacity_);
}

template<typename T>
Mvector<T>::bIterator Mvector<T>::begin() {
    return bIterator(arr_);
}

template<typename T>
Mvector<T>::bIterator Mvector<T>::end() {
    return bIterator(arr_ + size_);
}

template<typename T>
Mvector<T>::constIterator Mvector<T>::cbegin() const {
    return constIterator(arr_);
}

template<typename T>
Mvector<T>::constIterator Mvector<T>::cend() const {
    return constIterator(arr_ + size_);
}

template<typename T>
Mvector<T>::rIterator Mvector<T>::rbegin() {
    return rIterator(arr_ + size_);
}

template<typename T>
Mvector<T>::rIterator Mvector<T>::rend() {
    return rIterator(arr_);
}


template class Mvector<Mvector<Mvector<pair<pair<std::string, std::string>, pair<std::string, std::string>>>>>;
template class Mvector<Mvector<pair<pair<std::string, std::string>, pair<std::string, std::string>>>>;
template class Mvector<int>;
template class Mvector<pair<Mvector<int>, Mvector<pair<int, double>>>>;
template class Mvector<pair<int, double>>;
