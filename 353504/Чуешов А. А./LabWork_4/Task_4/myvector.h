#ifndef VECTOR_MYVEC_H
#define VECTOR_MYVEC_H

#include <cstddef>
#include <cstdlib>
#include <limits>
#include <stdexcept>
#include <utility>

#include "iterator.h"

template <typename T>

class MyVec
{
    using b_iterator = iterator<T>;
    using r_iterator = reverse_iterator<T>;
    using c_iterator = iterator<const T>;

public:

    MyVec();
    explicit MyVec(size_t n);
    MyVec(const MyVec<T>  &tmp);
    ~MyVec() noexcept;

    size_t size() const;
    size_t capacity() const;
    size_t max_size() const;

    void reserve(size_t n);
    void resize(size_t n, const T& value = T());
    void push_back(const T& value);
    void pop_back();
    void swap(MyVec<T>& vec);
    void clear();
    void insert(MyVec::b_iterator pos, T const &tmp_);
    template<typename ... Args>
    void emplace_back(Args &&... args);
    template<typename... Args>
    void emplace(MyVec::c_iterator pos, Args &&... args);
    void assign(MyVec::c_iterator beg, MyVec::c_iterator end);
    void erase(MyVec<T>::b_iterator beg, MyVec<T>::b_iterator end);

    bool empty();

    T* data();

    T& operator [] (size_t i);
    T& operator [] (size_t i) const;
    T& at(size_t i);
    T& front();
    T& back();

    c_iterator cbegin() const;
    c_iterator cend() const;

    b_iterator begin();
    b_iterator end();

    r_iterator rbegin();
    r_iterator rend();

private:

    T* arr;
    size_t _size{};
    size_t _capacity{};

};

template<typename T>
MyVec<T>::MyVec() : arr(nullptr), _size(0), _capacity(0)
{}

template<typename T>
MyVec<T>::MyVec(size_t n)
{
    reserve(n);
    for (size_t i = 0; i < n; i++)
    {
        new(arr + i) T();
    }
}

template<typename T>
MyVec<T>::MyVec(MyVec<T> const &tmp)
{
    _size = tmp.size();
    _capacity = tmp.capacity();
    arr = reinterpret_cast<T*>(new int8_t[_size * sizeof(T)]);
    for (size_t i = 0; i < _size; i++)
    {
        if (i < tmp.size())
        {
            new (arr + i) T(tmp[i]);
        }
        else
        {
            new (arr + i) T();
        }
    }
}

template<typename T>
MyVec<T>::~MyVec() noexcept
{
    clear();
    delete[] reinterpret_cast<int8_t*>(arr);
    _capacity = 0;
    _size = 0;
}

template <typename T>
size_t MyVec<T>::size() const
{
    return _size;
}

template <typename T>
size_t MyVec<T>::capacity() const
{
    return _capacity;
}

template<typename T>
size_t MyVec<T>::max_size() const
{
    return std::numeric_limits<std::size_t>::max() / sizeof(T);
}

template<typename T>
void MyVec<T>::reserve(size_t n_size)
{
    if (n_size <= _capacity)
    {
        return;
    }

    T *newArray = reinterpret_cast<T *>(new int8_t[sizeof(T) * n_size]);
    std::size_t index = 0;
    try
    {
        for (; index < _size; ++index)
        {
            new (newArray + index) T(arr[index]);
        }
    }
    catch (...)
    {
        for (size_t j = 0; j < index; ++j)
        {
            (newArray + j)->~T();
        }
        delete[] reinterpret_cast<int8_t *>(newArray);
        throw;
    }

    for (size_t i = 0; i < _size; ++i)
    {
        (arr + i)->~T();
    }
    if (!empty())
    {
        delete[] reinterpret_cast<int8_t *>(arr);
    }
    arr = newArray;
    _capacity = n_size;
}

template<typename T>
void MyVec<T>::resize(size_t n, const T &value)
{
    if(n > _capacity)
    {
        reserve(n);
    }
    for (int i = _size; i < n; ++i)
    {
        new (arr + i) T(value);
    }
    if(n < _size)
    {
        _size = n;
    }

}

template<typename T>
void MyVec<T>::push_back(const T &value)
{
    if(_capacity == 0)
    {
        reserve(1);
        return;
    }
    if(_capacity >= _size)
    {
        reserve(_size * 2);
    }
    try
    {
        new (arr + _size) T(value);
    }
    catch(...)
    {
        throw;
    }
    ++_size;
}

template<typename T>
void MyVec<T>::pop_back()
{
    --_size;
    (arr + _size)->~T();
}

template<typename T>
void MyVec<T>::swap(MyVec<T>& vec)
{
    std::swap(vec._capacity,_capacity);
    std::swap(vec._size,_size);
    std::swap(vec.arr,arr);
}

template<typename T>
void MyVec<T>::clear()
{
    for (size_t i = 0; i < _size; ++i)
    {
        (arr + i)->~T();
    }
    reserve(0);
    arr = nullptr;
    _capacity = 0;
    _size = 0;
}

template<typename T>
void MyVec<T>::insert(MyVec::b_iterator _pos, T const &tmp)
{
    auto pos = _pos.base() - arr;
    if (_size == _capacity)
    {
        reserve(_capacity == 0 ? 1 : _size * 2);
    }
    for (size_t i = _size; i > pos; --i)
    {
        new(arr + i) T(std::move(arr[i - 1]));
        (arr + i - 1)->~T();
    }
    new(arr + pos) T(tmp);
    ++_size;
}

template<typename T>
template<typename... Args>
void MyVec<T>::emplace_back(Args &&... args)
{
    if (_size == _capacity)
    {
        reserve(_capacity == 0 ? 1 : _size * 2);
    }
    new (arr + _size) T(std::forward<Args>(args)...);
    ++_size;
}

template<typename T>
void MyVec<T>::assign(MyVec::c_iterator beg, MyVec::c_iterator end)
{
    clear();
    int sz = end.base() - beg.base();
    resize(sz);
    for (auto i = 0; i < sz; i++)
    {
        new(arr + i) T(*(beg + i));
    }
}

template<typename T>
void MyVec<T>::erase(MyVec<T>::b_iterator beg, MyVec<T>::b_iterator end)
{
    int it_1 = beg.base() - arr;
    int it_2 = end.base() - arr;
    int len = it_2 - it_1;
    for (auto i = it_1; i <= it_2; i++)
    {
        (arr + i)->~T();
        new(arr + i) T(arr[i + 1]);
    }
    _size = _size - len;
}

template<typename T>
template<typename... Args>
void MyVec<T>::emplace(MyVec::c_iterator pos, Args &&... args)
{
    T tmp(args...);
    insert(pos, tmp);
}

template<typename T>
T& MyVec<T>::operator [](size_t i)
{
    return arr[i];
}

template<typename T>
T& MyVec<T>::operator [](size_t i) const
{
    return arr[i];
}

template<typename T>
T &MyVec<T>::at(size_t i)
{

    if(i >= _size)
    {
        throw std::out_of_range("MyVec -- out of range!");
    }
    return arr[i];
}

template<typename T>
bool MyVec<T>::empty()
{
    return _size == 0;
}

template<typename T>
T *MyVec<T>::data()
{
    return arr;
}

template<typename T>
typename MyVec<T>::c_iterator MyVec<T>::cbegin() const
{
    return c_iterator(arr);
}

template<typename T>
typename MyVec<T>::c_iterator MyVec<T>::cend() const
{
    return c_iterator(arr + _size);
}

template<typename T>
typename MyVec<T>::b_iterator MyVec<T>::begin()
{
    return b_iterator(arr);
}

template<typename T>
typename MyVec<T>::b_iterator MyVec<T>::end()
{
    return b_iterator(arr + _size);
}

template<typename T>
typename MyVec<T>::r_iterator MyVec<T>::rbegin()
{
    return r_iterator(arr);
}

template<typename T>
typename MyVec<T>::r_iterator MyVec<T>::rend()
{
    return r_iterator(arr + _size);
}

template<typename T>
T &MyVec<T>::front()
{
    if(this->empty())
    {
        throw std::out_of_range("front() called on an empty vector");
    }
    return arr[0];
}

template<typename T>
T &MyVec<T>::back()
{
    if(this->empty())
    {
        throw std::out_of_range("back() called on an empty vector");
    }
    return arr[_size];
}
#endif//VECTOR_MYVEC_H
