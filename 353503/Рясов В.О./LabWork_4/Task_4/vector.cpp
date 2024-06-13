#include "vector.h"
#include <algorithm>
#include <stdexcept>

template<typename T>
Vector<T>::Vector()
    : array(nullptr)
{}

template<typename T>
Vector<T>::Vector(size_t n_size)
{
    reserve(n_size);
    for (size_t index = 0; index < n_size; ++index) {
        new (array + index) T();
    }
    size_ = n_size;
}

template<typename T>
Vector<T>::~Vector()
{
    for (size_t index = 0; index < size_; ++index) {
        (array + index)->~T();
    }
    delete[] reinterpret_cast<int8_t *>(array);
}

template<typename T>
void Vector<T>::assign(size_t n_size, T value)
{
    clear();
    resize(n_size, value);
}

template<typename T>
void Vector<T>::assign(const_iterator begin, const_iterator end)
{
    clear();
    resize(end.base() - begin.base());
    for (time_t index = 0; index < (end.base() - begin.base()); ++index) {
        new (array + index) T(*(begin + index));
    }
}

template<typename T>
T &Vector<T>::at(size_t index)
{
    if (index >= size_) {
        throw std::out_of_range("...");
    }
    return array[index];
}

template<typename T>
T &Vector<T>::back()
{
    if (empty()) {
        throw std::out_of_range("...");
    }
    return array[size_ - 1];
}

template<typename T>
std::size_t Vector<T>::capacity() const
{
    return capacity_;
}

template<typename T>
void Vector<T>::clear()
{
    resize(0);
}

template<typename T>
T *Vector<T>::data()
{
    if (empty()) {
        throw std::out_of_range("...");
    }
    return array;
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace(size_t pos, Args &&...args)
{
    if (size_ == capacity_) {
        reserve(size_ + 1);
    }
    if (size_ > 0) {
        for (size_t i = size_; i > pos; --i) {
            new (array + i) T(std::move(array[i - 1]));
            array[i - 1].~T();
        }
    }
    new (array + pos) T(std::forward<Args>(args)...);
    ++size_;
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(Args &&...args)
{
    T value(args...);
    push_back(value);
}

template<typename T>
bool Vector<T>::empty()
{
    return size_ == 0;
}

template<typename T>
void Vector<T>::erase(iterator value)
{
    erase(value, value + 1);
}

template<typename T>
void Vector<T>::erase(iterator begin, iterator end)
{
    size_t index1 = begin.base() - array;
    size_t index2 = end.base() - array;
    size_t numElems = index2 - index1;

    for (size_t i = index1; i < index2; ++i) {
        (array + i)->~T();
    }

    for (size_t i = index2; i < size_; ++i) {
        new (array + i - numElems) T(std::move(array[i]));
        array[i].~T();
    }

    size_ -= numElems;
}

template<typename T>
T &Vector<T>::front()
{
    if (empty()) {
        throw std::out_of_range("...");
    }
    return *array;
}

template<typename T>
void Vector<T>::insert(size_t pos, const T &value)
{
    if (size_ == capacity_) {
        reserve(size_ + 1);
    }
    if (size_ > 0) {
        for (size_t i = size_; i > pos; --i) {
            new (array + i) T(std::move(array[i - 1]));
            array[i - 1].~T();
        }
    }
    new (array + pos) T(value);
    ++size_;
}

template<typename T>
std::size_t Vector<T>::max_size()
{
    return __INT64_MAX__ / sizeof(T);
}

template<typename T>
void Vector<T>::pop_back()
{
    if (!empty()) {
        (array + size_ - 1)->~T();
        --size_;
    } else {
        throw std::out_of_range("...");
    }
}

template<typename T>
void Vector<T>::push_back(const T &value)
{
    if (capacity_ == 0) {
        reserve(capacity_ + 1);
    } else if (size_ == capacity_) {
        reserve(2 * size_);
    }
    try {
        new (array + size_) T(value);
    } catch (...) {
        throw;
    }
    ++size_;
}

template<typename T>
void Vector<T>::reserve(size_t n_size)
{
    if (n_size <= capacity_) {
        return;
    }

    T *newArray = reinterpret_cast<T *>(new int8_t[sizeof(T) * n_size]);
    std::size_t index = 0;
    try {
        for (; index < size_; ++index) {
            new (newArray + index) T(std::move(array[index]));
        }
    } catch (...) {
        for (size_t j = 0; j < index; ++j) {
            (newArray + j)->~T();
        }
        delete[] reinterpret_cast<int8_t *>(newArray);
        throw;
    }

    for (size_t i = 0; i < size_; ++i) {
        (array + i)->~T();
    }
    if (!empty()) {
        delete[] reinterpret_cast<int8_t *>(array);
    }
    array = newArray;
    capacity_ = n_size;
}

template<typename T>
void Vector<T>::resize(size_t n_size, const T &value)
{
    if (n_size > capacity_) {
        reserve(n_size);
    }

    size_t index = size_;
    try {
        for (; index < n_size; ++index) {
            new (array + index) T(value);
        }
    } catch (...) {
        for (size_t j = size_; j < index; ++j) {
            (array + j)->~T();
            delete reinterpret_cast<int8_t *>(array + j);
        }
        throw;
    }

    for (size_t iter = n_size; iter < size_; ++iter) {
        (array + iter)->~T();
    }
    size_ = n_size;
}

template<typename T>
std::size_t Vector<T>::size() const
{
    return size_;
}

template<typename T>
void Vector<T>::swap(Vector<T> &value)
{
    std::swap(array, value.array);
    std::swap(size_, value.size_);
    std::swap(capacity_, value.capacity_);
}

template<typename T>
const T &Vector<T>::operator[](size_t index) const
{
    return array[index];
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin()
{
    return iterator(array);
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end()
{
    return iterator(array + size_);
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const
{
    return const_iterator(array);
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cend() const
{
    return const_iterator(array + size_);
}

template<typename T>
T &Vector<T>::operator[](size_t index)
{
    return array[index];
}

template class Vector<int8_t>;
template class Vector<int16_t>;
template class Vector<int32_t>;
template class Vector<int64_t>;
template class Vector<u_int8_t>;
template class Vector<u_int16_t>;
template class Vector<u_int32_t>;
template class Vector<u_int64_t>;
template class Vector<float>;
template class Vector<double>;
template class Vector<long double>;
template class Vector<char>;
