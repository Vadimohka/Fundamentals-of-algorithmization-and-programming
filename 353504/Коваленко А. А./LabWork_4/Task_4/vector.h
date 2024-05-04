#ifndef VECTOR_H
#define VECTOR_H

#include "iterator.h"
#include <initializer_list>
#include <QCoreApplication>
#include <QTime>

template<typename T>
class Vector
{
    using iterator = Iterator<T>;
    using rIterator = ReverseIterator<T>;
    using cIterator = Iterator<const T>;

    T *_array = nullptr;
    unsigned long long _size = 0;
    unsigned long long _capacity = 0;

public:
    Vector()
    {
        _array = nullptr;
        _size = 0;
        _capacity = 0;
    }

    Vector(unsigned long long n)
    {
        reserve(n);
        for (unsigned long long i = 0; i < n; ++i)
        {
            new (_array + i) T();
        }
    }

    Vector(Vector<T> const &temp)
    {
        _size = temp._size;
        _capacity = temp._capacity;
        _array = reinterpret_cast<T*>(new short[_size * sizeof(T)]);
        for (unsigned long long i = 0; i < _size; ++i)
        {
            new (_array + i) T(temp[i]);
        }
    }

    Vector(std::initializer_list<T> temp)
    {
        _size = temp.size();
        _capacity = temp.size();
        auto iter = temp.begin();
        _array = new T[_size];
        for (unsigned long long i = 0; i < _size; ++i, ++iter)
        {
            T temp = *iter;
            new (_array + i) T(std::move(temp));
        }
    }

    ~Vector()
    {
        for (int i = 0; i < _size; ++i)
        {
            (_array + i)->~T();
        }
        delete[] _array;
        _array = nullptr;
        _capacity = 0;
        _size = 0;
    }

    T &operator[](unsigned long long index) const
    {
        return _array[index];
    }

    template<typename... Args>
    void emplace(Vector::cIterator pos, Args &&... args)
    {
        T temp(args...);
        insert(pos, temp);
    }

    template<typename... Args>
    void emplace_back(Args &&... args)
    {
        T temp(args...);
        push_back(temp);
    }

    void insert(Vector::cIterator pos, T const &temp)
    {
        unsigned long long _pos = (pos).base() - _array;
        reserve(_size + 1);
        for (unsigned long long i = _size; i > _pos; --i)
        {
            new (_array + i) T(_array[i - 1]);
            (_array + i - 1)->~T();
        }
        new(_array + _pos) T(temp);
        ++_size;
    }

    void insert(Vector::cIterator pos, T &&temp)
    {
        unsigned long long _pos = pos.base() - _array;
        reserve(_size + 1);
        for (unsigned long long i = _size; i > _pos; --i)
        {
            new (_array + i) T(_array[i - 1]);
            (_array + i - 1)->~T();
        }
        new(_array + _pos) T(temp);
        ++_size;
    }

    void pop_back()
    {
        if (empty())
        {
            return;
        }
        (_array + _size - 1)->~T();
        --_size;
    }

    void push_back(T temp)
    {
        if (_size >= _capacity)
        {
            reserve(2 * _size + 1);
        }
        new (_array + _size) T(temp);
        ++_size;
    }

    void assign(unsigned long long n, T temp)
    {
        clear();
        resize(n, temp);
    }

    void assign(Vector::cIterator begin, Vector::cIterator end)
    {
        clear();
        unsigned long long size = end.base() - begin.base();
        resize(size);
        for (unsigned long long i = 0; i < size; ++i)
        {
            new (_array + i) T(*(begin + i));
        }
    }

    void clear()
    {
        resize(0);
    }

    void erase(Vector::iterator temp)
    {
        erase(temp, temp + 1);
    }

    void erase(Vector<T>::iterator begin, Vector<T>::iterator end)
    {
        unsigned long long j = begin.base() - _array;
        unsigned long long k = end.base() - _array;
        for (unsigned long long i = j; i < k; ++i)
        {
            (_array + i)->~T();
            new (_array + i) T(_array[i + 1]);
        }
        _size -= k - j;
    }

    T &back()
    {
        return _array[_size - 1];
    }

    T &front()
    {
        return _array[0];
    }

    T &at(unsigned long long pos)
    {
        if (pos > _size)
        {
            throw std::out_of_range("");
        }
        try
        {
            return _array[pos];
        } catch (...)
        {
            throw std::out_of_range("");
        }
    }

    T *data()
    {
        return _array;
    }

    unsigned long long capacity()
    {
        return _capacity;
    }

    unsigned long long size()
    {
        return _size;
    }

    unsigned long long max_size()
    {
        return INT64_MAX / sizeof(T);
    }

    bool empty()
    {
        return _size == 0;
    }

    void resize(unsigned long long size, T temp = T())
    {
        if (size > _capacity)
        {
            reserve(size);
        }
        for (unsigned long long i = _size; i < size; ++i)
        {
            new (_array + i) T(temp);
        }
        for (unsigned long long i = size; i < _size; ++i)
        {
            (_array + i)->~T();
        }
        _size = size;
    }

    void reserve(unsigned long long size)
    {
        if (size <= _capacity)
        {
            return;
        }
        T *temp = new T[size];
        for (int i = 0; i < _size; ++i)
        {
            new (temp + i) T(_array[i]);
            (_array + i)->~T();
        }
        delete[] _array;
        _array = temp;
        _capacity = size;
    }

    Vector<T>::iterator begin()
    {
        return iterator(_array);
    }

    Vector<T>::iterator end()
    {
        return iterator(_array + _size);
    }

    Vector<T>::rIterator rbegin()
    {
        return rIterator(_array);
    }

    Vector<T>::rIterator rend()
    {
        return rIterator(_array + _size);
    }

    Vector<T>::cIterator cbegin() const
    {
        return cIterator(_array);
    }

    Vector<T>::cIterator cend() const
    {
        return cIterator(_array + _size);
    }

    void swap(Vector<T> &to)
    {
        std::swap(_array, to._array);
        std::swap(_size, to._size);
        std::swap(_capacity, to.capacity());
    }

};

#endif // VECTOR_H
