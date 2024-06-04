#pragma once

#include <array>
#include <cstddef>
#include <stdexcept>
#include <climits>
#include "iterator.h"

using std::size_t;

//Vector
template <typename T>
class Vector {
public:
    using iterator = Iterator<T>;
    using const_iterator = Iterator<const T>;
    using reverse_iterator = Reverse_Iterator<T>;
    using const_reverse_iterator = Reverse_Iterator<const T>;

private:
    T* m_Data = nullptr;
    size_t m_Size = 0;
    size_t m_Capacity = 0;

public:
    Vector() {
        resize(2);
    }

    T& operator[](size_t index) { return m_Data[index]; }
    const T& operator[](size_t index) const { return m_Data[index]; }

public:
    void resize(size_t newCapacity);
    void reserve(size_t newCapacity);
    void push_back(const T& value);
    void pop_back();

    size_t size();
    size_t capacity();
    size_t max_size();

    bool empty();

    const T& at(size_t pos) const;
    T* data();
    T& front();
    T& back();
    
    iterator begin();
    iterator end();
    const_iterator cbegin() const;
    const_iterator cend() const;
    reverse_iterator rbegin();
    reverse_iterator rend();

    void erase(iterator pos);
    void erase(iterator first, iterator last);
    void swap(Vector& other);
    void assign(size_t count, const T& value);
    void clear();

    void insert(const_iterator pos, const T& value);
    template<class... Args>
    void emplace(const_iterator pos, Args&&... args);
    template<typename ... Args>
    void emplace_back(Args &&... args);
};

template<typename T>
void Vector<T>::resize(size_t newCapacity) {
    if (newCapacity > m_Capacity)
        reserve(newCapacity);

    for (size_t i = m_Size; i < newCapacity; i++) {
        new(m_Data + i) T();
    }
    for (size_t i = newCapacity; i < m_Size; i++) {
        (m_Data + i)->~T();
    }

    m_Capacity = newCapacity;
    if (m_Size > m_Capacity) {
        m_Size = m_Capacity;
    }
}

template<typename T>
void Vector<T>::reserve(size_t newCapacity) {
    if (newCapacity <= m_Capacity)
        return;
    
    T* newBlock = new T[newCapacity];
    for (size_t i = 0; i < m_Size; ++i) 
        newBlock[i] = m_Data[i];
    
    delete[] m_Data;
    m_Data = newBlock;
    m_Capacity = newCapacity;
}

template<typename T>
void Vector<T>::push_back(const T& value) {
    if (m_Size >= m_Capacity)
        resize(m_Capacity * 2);
     
    m_Data[m_Size++] = value;
}

template<typename T>
void Vector<T>::pop_back() {
    if (m_Size == 0)
        return;

    --m_Size;
}

template<typename T>
Iterator<T> Vector<T>::begin() { return iterator(m_Data); }

template<typename T>
Iterator<T> Vector<T>::end() { return iterator(m_Data + m_Size); }

template<typename T>
Iterator<const T> Vector<T>::cbegin() const { return const_iterator(m_Data); }

template<typename T>
Iterator<const T> Vector<T>::cend() const { return const_iterator(m_Data + m_Size); }

template<typename T>
Reverse_Iterator<T> Vector<T>::rbegin() { return iterator(m_Data + m_Size); }

template<typename T>
Reverse_Iterator<T> Vector<T>::rend() { return iterator(m_Data); }

template<typename T>
size_t Vector<T>::size() { return m_Size; }

template<typename T>
size_t Vector<T>::capacity() { return m_Capacity; }

template<typename T>
size_t Vector<T>::max_size() { return LLONG_MAX / sizeof(T); }

template<typename T>
bool Vector<T>::empty() { return m_Size == 0; }

template<typename T> void Vector<T>::clear() { resize(0); }

template<typename T> 
void Vector<T>::swap(Vector& other){
    std::swap(m_Data, other.m_Data);
    std::swap(m_Size, other.m_Size);
    std::swap(m_Capacity, other.m_Capacity);
}

template<typename T> 
void Vector<T>::assign(size_t count, const T& value){
    clear();
    reserve(count);

    for (size_t i = 0; i < count; i++) {
        m_Data[i] = value;
    }

    m_Size = count;
}

template<typename T>
void Vector<T>::erase(iterator pos) {
    erase(pos, pos + 1);
}

template<typename T>
void Vector<T>::erase(iterator first, iterator last)
{
    if (first == last) 
        return;

    if (first < begin() || last > end() || first > last)
        throw std::out_of_range("Iterators out of bounds");

    auto it1 = first.base() - m_Data;
    auto it2 = last.base() - m_Data;
    auto eraseCount = it2 - it1;

    for (auto i = it2; i < m_Size; ++i) {
        (m_Data + i - eraseCount)->~T(); //m_data +it1 + 1 + 2...
        new(m_Data + i - eraseCount) T(std::move(m_Data[i]));
        (m_Data + i)->~T();
    }

    m_Size -= eraseCount;
}

template<typename T>
void Vector<T>::insert(const_iterator pos, const T& value){
    if (pos < cbegin() || pos > cend())
        throw std::out_of_range("Invalid index");

    size_t index = pos - cbegin();
    
    if (m_Size >= m_Capacity)
        resize(m_Capacity * 2);
    
    for (size_t i = m_Size; i > index; --i) {
        m_Data[i] = m_Data[i - 1];
    }

    m_Data[index] = value;
    ++m_Size;
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace(const_iterator pos, Args &&... args){
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
const T& Vector<T>::at(size_t pos) const {
    try {
        return m_Data[pos];
    } catch (...) {
        throw std::out_of_range("invalid index");
    }
}

template <typename T>
T& Vector<T>::front() { return m_Data[0]; }

template <typename T>
T& Vector<T>::back() { return m_Data[m_Size-1]; }

template <typename T>
T* Vector<T>::data() { return m_Data; }