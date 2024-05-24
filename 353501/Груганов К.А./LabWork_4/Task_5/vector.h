#ifndef VECTOR_H
#define VECTOR_H

#include "iterator.h"
#include <algorithm>
#include <cstddef>
#include <initializer_list>
#include <limits>
#include <stdexcept>

template<typename T>
class Vector : public Iterator<T>
{
    using itr = Iterator<T>;
    using rev_itr = ReverseIterator<T>;
    using c_itr = ConstIterator<T>;
    using c_rev_itr = ConstReverseIterator<T>;

private:
    T *data;         //указатель на блок памяти
    size_t size;     //размер в байтах
    size_t capacity; //общее колво без выделения доп памяти

public:
    Vector();
    Vector(const Vector<T> &vec);
    Vector(Vector<T> &&vec) noexcept;
    Vector(std::initializer_list<T> init_list);
    ~Vector();

    T &operator[](size_t n) const;

    //методы
    T &at(size_t index);
    T &back();
    T *Data();
    T &front();

    itr end();
    itr begin();
    c_itr cbegin() const;
    rev_itr rbegin();
    rev_itr rend();

    size_t getCapacity() const;
    size_t max_size();
    size_t Size();

    void assign(size_t count, const T &val);
    void clear();
    //&&-универсальная ссылка с r-val и l-val
    template<typename... Args>
    void emplace(itr pos, Args &&...args);
    template<typename... Args>
    void emplace_back(Args &&...args);
    void reserve(size_t new_cap);
    void resize(size_t new_size);
    void pop_back();
    void push_back(const T &val);
    void erase(itr pos1, itr pos2);
    void insert(itr pos, const T &value);
    void swap(Vector<T> &vec);

    bool empty();
};

template<typename T>
T &Vector<T>::operator[](size_t n) const
{
    return data[n];
}

template<typename T>
template<typename... Types>
void Vector<T>::emplace(itr pos, Types &&...args)
{
    T temp(args...);
    insert(pos, temp);
}

template<typename T>
template<typename... Args>
void Vector<T>::emplace_back(Args &&...args)
{
    T tmp(args...);
    push_back(tmp);
}

//конструктор по умол
template<typename T>
Vector<T>::Vector()
{
    data = nullptr;
    size = 0;
    capacity = 0;
}

//конструктор копирования
template<typename T>
Vector<T>::Vector(const Vector<T> &vec)
{
    data = new T[vec.capacity];
    size = vec.size;
    capacity = vec.capacity;
}

//констуктор перемещения(мув)
template<typename T>
Vector<T>::Vector(Vector<T> &&vec) noexcept
    : data(vec.data)
    , size(vec.size)
    , capacity(vec.capacity)
{
    vec.data = nullptr;
    vec.size = 0;
    vec.capacity = 0;
}

//инициализирующий конструктор
template<typename T>
Vector<T>::Vector(std::initializer_list<T> init_list)
{
    data = new T[init_list.size()];
    init_list.size();
    capacity = init_list.size();

    std::copy(init_list.begin(), init_list.end(), data);
}

template<typename T>
Vector<T>::~Vector()
{
    delete[] data;
}

template<typename T>
void Vector<T>::assign(size_t n, const T &val)
{
    if (data != nullptr) {
        delete[] data;
    }

    data = new T[n];
    size = n;
    capacity = n;
    std::fill(data, data + n, val);
}

template<typename T>
T &Vector<T>::at(size_t index)
{
    if (index >= size)
        throw std::out_of_range("Index is out of range");
    return data[index];
}

template<typename T>
T &Vector<T>::back()
{
    return data[size - 1];
}

template<typename T>
typename Vector<T>::itr Vector<T>::begin()
{
    return itr(data);
}

template<typename T>
typename Vector<T>::c_itr Vector<T>::cbegin() const
{
    return c_itr(data);
}

template<typename T>
size_t Vector<T>::getCapacity() const
{
    return capacity;
}

template<typename T>
void Vector<T>::clear()
{
    if (data != nullptr) {
        delete[] data;
    }
    data = nullptr;
    size = 0;
    capacity = 0;
}

template<typename T>
T *Vector<T>::Data()
{
    return data;
}

template<typename T>
bool Vector<T>::empty()
{
    return size == 0;
}

template<typename T>
typename Vector<T>::itr Vector<T>::end()
{
    return itr(data + size);
}

template<typename T>
void Vector<T>::erase(itr pos1, itr pos2)
{
    if (pos1 < begin() || pos2 > end() || pos1 > pos2) {
        throw std::out_of_range("Iterator is out of range");
        size_t elementsToRemove = pos2 - pos1;
        itr i = pos1;
        itr j = pos2;

        while (j != end()) {
            *i = std::move(*j);
            ++i;
            ++j;
        }

        size -= elementsToRemove;

        for (size_t i = 0; i < elementsToRemove; i++) {
            data[size + i].~T();
        }
    }
}

template<typename T>
T &Vector<T>::front()
{
    if (size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    return data[0];
}

template<typename T>
void Vector<T>::insert(itr pos, const T &value)
{
    if (pos < begin() || pos > end()) {
        throw std::out_of_range("Iterator is out of range");
    }

    size_t index = pos - begin();

    if (size == capacity) {
        T *new_data = new T[capacity * 2];
        delete[] data;
        data = new_data;
        capacity *= 2;
        pos = data + index;
    }

    for (itr i = end(); i != pos; --i)
        *(i) = *(i - 1);
    *pos = value;
    ++size;
}

template<typename T>
size_t Vector<T>::max_size()
{
    return std::numeric_limits<size_t>::max() / sizeof(T);
}

template<typename T>
void Vector<T>::pop_back()
{
    if (size == 0) {
        throw std::out_of_range("Vector is empty");
    }
    (data + size - 1)->~T();
    --size;
}

template<typename T>
void Vector<T>::push_back(const T &val)
{
    if (size >= capacity) {
        reserve(size + 1);
    }
    data[size] = val;
    ++size;
}

template<typename T>
typename Vector<T>::rev_itr Vector<T>::rbegin()
{
    return rev_itr(data + size);
}

template<typename T>
typename Vector<T>::rev_itr Vector<T>::rend()
{
    return rev_itr(data);
}

template<typename T>
void Vector<T>::reserve(size_t new_cap)
{
    if (new_cap > max_size()) {
        throw std::length_error("Vector capacity exceeds max_size");
    }
    if (new_cap <= capacity) {
        return;
    }
    T *new_data = new T[new_cap];
    std::copy(data, data + size, new_data);

    delete[] data;
    data = new_data;
    capacity = new_cap;
}

template<typename T>
void Vector<T>::resize(size_t new_size)
{
    if (new_size > max_size()) {
        throw std::length_error("Vector capacity exceeds maximum size");
    }

    if (new_size > size) {
        reserve(new_size);
        for (size_t i = size; i < new_size; i++) {
            data[i] = T();
        }

    } else if (new_size < size) {
        for (size_t i = new_size; i < size; ++i) {
            data[i].~T();
        }
    }
    size = new_size;
}
template<typename T>
size_t Vector<T>::Size()
{
    return size;
}

template<typename T>
void Vector<T>::swap(Vector<T> &vec)
{
    std::swap(data, vec.data);
    std::swap(size, vec.size);
    std::swap(capacity, vec.capacity);
}

#endif // VECTOR_H
