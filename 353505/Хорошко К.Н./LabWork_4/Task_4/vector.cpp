#include <stdexcept>
#include "vector.h"
#include "pair.h"
#include <memory>
#include <initializer_list>

template<typename T>
Vector<T>::Vector() : arr_(nullptr), size_(0), capacity_(0) {}

template<typename T>
Vector<T>::Vector(size_t n) : size_(n), capacity_(n) {
    arr_ = reinterpret_cast<T*>(new int8_t[capacity_ * sizeof(T)]);
    for (size_t i = 0; i < size_; ++i) {
        new (arr_ + i) T();
    }
}

template<typename T>
Vector<T>::Vector(Vector<T> const &other) : size_(other.size_), capacity_(other.capacity_) {
    arr_ = reinterpret_cast<T*>(new int8_t[capacity_ * sizeof(T)]);
    for (size_t i = 0; i < size_; ++i) {
        new (arr_ + i) T(other.arr_[i]);
    }
}

template<typename T>
Vector<T>::Vector(std::initializer_list<T> init_list)
    : size_(init_list.size()), capacity_(init_list.size()) {
    arr_ = reinterpret_cast<T*>(new int8_t[capacity_ * sizeof(T)]);
    auto it = init_list.begin();
    for (size_t i = 0; i < size_; ++i, ++it) {
        new (arr_ + i) T(*it);
    }
}

template<typename T>
Vector<T>::~Vector() {
    for (size_t i = 0; i < size_; ++i) {
        arr_[i].~T();
    }
    delete[] reinterpret_cast<int8_t*>(arr_);
    arr_ = nullptr;
    size_ = capacity_ = 0;
}

template<typename T>
T &Vector<T>::operator[](size_t index) const {
    return arr_[index];
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace(typename Vector<T>::c_iterator pos, Args&&... args) {
    T temp(std::forward<Args>(args)...);
    insert(pos, std::move(temp));
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(Args&&... args) {
    T temp(std::forward<Args>(args)...);
    push_back(std::move(temp));
}

template<typename T>
void Vector<T>::insert(typename Vector<T>::c_iterator pos, T const &value) {
    size_t index = pos.base() - arr_;
    reserve(size_ + 1);
    for (size_t i = size_; i > index; --i) {
        new (arr_ + i) T(std::move(arr_[i - 1]));
        arr_[i - 1].~T();
    }
    new (arr_ + index) T(value);
    ++size_;
}

template<typename T>
void Vector<T>::insert(typename Vector<T>::c_iterator pos, T &&value) {
    size_t index = pos.base() - arr_;
    if (size_ >= capacity_) reserve(2 * size_ + 1);
    for (size_t i = size_; i > index; --i) {
        new (arr_ + i) T(std::move(arr_[i - 1]));
        arr_[i - 1].~T();
    }
    new (arr_ + index) T(std::move(value));
    ++size_;
}

template<typename T>
void Vector<T>::push_back(T value) {
    if (size_ >= capacity_) reserve(2 * size_ + 1);
    new (arr_ + size_) T(std::move(value));
    ++size_;
}

template<typename T>
void Vector<T>::assign(size_t n, T value) {
    clear();
    resize(n, value);
}

template<typename T>
void Vector<T>::assign(typename Vector<T>::c_iterator first, typename Vector<T>::c_iterator last) {
    clear();
    size_t newSize = last.base() - first.base();
    resize(newSize);
    for (size_t i = 0; i < newSize; ++i) {
        new (arr_ + i) T(*(first + i));
    }
}

template<typename T>
void Vector<T>::clear() {
    resize(0);
}

template<typename T>
void Vector<T>::erase(typename Vector<T>::b_iterator pos) {
    erase(pos, pos + 1);
}

template<typename T>
void Vector<T>::erase(typename Vector<T>::b_iterator first, typename Vector<T>::b_iterator last) {
    size_t firstIndex = first.base() - arr_;
    size_t lastIndex = last.base() - arr_;
    for (size_t i = firstIndex; i < lastIndex; ++i) {
        arr_[i].~T();
    }
    for (size_t i = lastIndex; i < size_; ++i) {
        new (arr_ + i - (lastIndex - firstIndex)) T(std::move(arr_[i]));
        arr_[i].~T();
    }
    size_ -= (lastIndex - firstIndex);
}

template<typename T>
void Vector<T>::pop_back() {
    if (!empty()) {
        arr_[size_ - 1].~T();
        --size_;
    }
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
T &Vector<T>::at(size_t pos) {
    if (pos >= size_) throw std::out_of_range("Index out of range");
    return arr_[pos];
}

template<typename T>
T *Vector<T>::data() {
    return arr_;
}

template<typename T>
size_t Vector<T>::capacity() const {
    return capacity_;
}

template<typename T>
size_t Vector<T>::size() const {
    return size_;
}

template<typename T>
size_t Vector<T>::max_size() const {
    return static_cast<size_t>(-1) / sizeof(T);
}

template<typename T>
void Vector<T>::resize(size_t newSize, T value) {
    if (newSize > capacity_) reserve(newSize);
    for (size_t i = size_; i < newSize; ++i) {
        new (arr_ + i) T(value);
    }
    for (size_t i = newSize; i < size_; ++i) {
        arr_[i].~T();
    }
    size_ = newSize;
}

template<typename T>
void Vector<T>::reserve(size_t newCapacity) {
    if (newCapacity <= capacity_) return;
    T *newArr = reinterpret_cast<T*>(new int8_t[newCapacity * sizeof(T)]);
    for (size_t i = 0; i < size_; ++i) {
        new (newArr + i) T(std::move(arr_[i]));
        arr_[i].~T();
    }
    delete[] reinterpret_cast<int8_t*>(arr_);
    arr_ = newArr;
    capacity_ = newCapacity;
}

template<typename T>
bool Vector<T>::empty() const {
    return size_ == 0;
}

template<typename T>
void Vector<T>::swap(Vector<T> &other) {
    std::swap(arr_, other.arr_);
    std::swap(size_, other.size_);
    std::swap(capacity_, other.capacity_);
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
