#ifndef VECTOR_H
#define VECTOR_H

#include <cstddef>  // for size_t
#include <utility>  // for std::swap, std::move

template<typename T>
class VectorIterator;

template<typename T>
class Vector {
public:
    using iterator = VectorIterator<T>;
    using const_iterator = const VectorIterator<T>;

    Vector();
    ~Vector();

    void assign(size_t count, const T& value);
    T& at(size_t pos);
    T& back();
    iterator begin();
    const_iterator cbegin() const;
    void clear();
    T* data();
    void emplace(size_t pos, T&& value);
    void emplace_back(T&& value);
    bool empty() const;
    iterator end();
    void erase(size_t pos);
    T& front();
    void insert(size_t pos, const T& value);
    size_t max_size() const;
    void pop_back();
    void push_back(const T& value);
    iterator rbegin();
    iterator rend();
    void reserve(size_t new_cap);
    void resize(size_t count);
    size_t size() const;
    void swap(Vector<T>& other);
    size_t capacity() const;

private:
    T* elements;
    size_t _size;
    size_t _capacity;

    void reallocate(size_t new_capacity);
};

#include "VectorIterator.h"

template<typename T>
Vector<T>::Vector() : elements(nullptr), _size(0), _capacity(0) {}

template<typename T>
Vector<T>::~Vector() {
    delete[] elements;
}

template<typename T>
void Vector<T>::assign(size_t count, const T& value) {
    delete[] elements;
    elements = new T[count];
    _size = count;
    _capacity = count;
    for (size_t i = 0; i < count; ++i) {
        elements[i] = value;
    }
}

template<typename T>
T& Vector<T>::at(size_t pos) {
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    return elements[pos];
}

template<typename T>
T& Vector<T>::back() {
    if (_size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return elements[_size - 1];
}

template<typename T>
typename Vector<T>::iterator Vector<T>::begin() {
    return iterator(elements);
}

template<typename T>
typename Vector<T>::const_iterator Vector<T>::cbegin() const {
    return const_iterator(elements);
}

template<typename T>
void Vector<T>::clear() {
    _size = 0;
}

template<typename T>
T* Vector<T>::data() {
    return elements;
}

template<typename T>
void Vector<T>::emplace(size_t pos, T&& value) {
    if (pos > _size) {
        throw std::out_of_range("Index out of range");
    }
    if (_size == _capacity) {
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    }
    for (size_t i = _size; i > pos; --i) {
        elements[i] = std::move(elements[i - 1]);
    }
    elements[pos] = std::move(value);
    ++_size;
}

template<typename T>
void Vector<T>::emplace_back(T&& value) {
    if (_size == _capacity) {
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    }
    elements[_size] = std::move(value);
    ++_size;
}

template<typename T>
bool Vector<T>::empty() const {
    return _size == 0;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::end() {
    return iterator(elements + _size);
}

template<typename T>
void Vector<T>::erase(size_t pos) {
    if (pos >= _size) {
        throw std::out_of_range("Index out of range");
    }
    for (size_t i = pos; i < _size - 1; ++i) {
        elements[i] = std::move(elements[i + 1]);
    }
    --_size;
}

template<typename T>
T& Vector<T>::front() {
    if (_size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return elements[0];
}

template<typename T>
void Vector<T>::insert(size_t pos, const T& value) {
    if (pos > _size) {
        throw std::out_of_range("Index out of range");
    }
    if (_size == _capacity) {
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    }
    for (size_t i = _size; i > pos; --i) {
        elements[i] = elements[i - 1];
    }
    elements[pos] = value;
    ++_size;
}

template<typename T>
size_t Vector<T>::max_size() const {
    return size_t(-1) / sizeof(T);
}

template<typename T>
void Vector<T>::pop_back() {
    if (_size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    --_size;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (_size == _capacity) {
        reserve(_capacity == 0 ? 1 : _capacity * 2);
    }
    elements[_size] = value;
    ++_size;
}

template<typename T>
typename Vector<T>::iterator Vector<T>::rbegin() {
    return iterator(elements + _size - 1);
}

template<typename T>
typename Vector<T>::iterator Vector<T>::rend() {
    return iterator(elements - 1);
}

template<typename T>
void Vector<T>::reserve(size_t new_cap) {
    if (new_cap > _capacity) {
        reallocate(new_cap);
    }
}

template<typename T>
void Vector<T>::resize(size_t count) {
    if (count > _capacity) {
        reserve(count);
    }
    _size = count;
}

template<typename T>
size_t Vector<T>::size() const {
    return _size;
}

template<typename T>
void Vector<T>::swap(Vector<T>& other) {
    std::swap(elements, other.elements);
    std::swap(_size, other._size);
    std::swap(_capacity, other._capacity);
}

template<typename T>
size_t Vector<T>::capacity() const {
    return _capacity;
}

template<typename T>
void Vector<T>::reallocate(size_t new_capacity) {
    T* new_elements = new T[new_capacity];
    for (size_t i = 0; i < _size; ++i) {
        new_elements[i] = std::move(elements[i]);
    }
    delete[] elements;
    elements = new_elements;
    _capacity = new_capacity;
}

#endif // VECTOR_H
