#ifndef MYVECTOR_H
#define MYVECTOR_H

#include "iterator.h"
#include <initializer_list>
#include <memory>
#include <stdexcept>

template<class T>
class MyVector : public Iterator<T>
{
private:
    T *_arr = nullptr;
    size_t _size{0};
    size_t _capacity{0};

public:
    MyVector()
        : _arr(new T[1])
        , _capacity(1)
    {}
    explicit MyVector(size_t n)
        : _size(n)
        , _capacity(n)
        , _arr(new T[n])
    {}

    MyVector(const MyVector<T> &other)
        : _size(other._size)
        , _capacity(other._capacity)
        , _arr(reinterpret_cast<T *>(new int8_t[sizeof(T) * other._capacity]))
    {
        std::uninitialized_copy(other._arr, other._arr + _size, _arr);
    }

    MyVector(std::initializer_list<T> param)
        : _capacity(param.size())
        , _size(param.size())
        , _arr(reinterpret_cast<T *>(new int8_t[sizeof(T) * param.size()]))
    {
        for (int i = 0; i < param.size(); i++) {
            new (_arr + i) T(*(param.begin() + i));
        }
    }

    MyVector &operator=(const MyVector &other)
    {
        if (this == &other) {
            return *this;
        }
        for (int i = 0; i < _size; ++i) {
            _arr[i].~T();
        }
        delete[] _arr;
        _capacity = other._capacity;
        _size = other._size;
        _arr = reinterpret_cast<T *>(new int8_t[sizeof(T) * other._capacity]);
        return *this;
    }

    ~MyVector()
    {
        for (int i = 0; i < _size; ++i) {
            _arr[i].~T();
        }
        _size = 0;
        _capacity = 0;
        _arr = nullptr;
    }

    T &operator[](size_t index) { return at(index); }

    void assign(size_t count, const T &elem)
    {
        clear();
        resize(count);
        for (int i = 0; i < count; i++) {
            new (_arr + i) T(elem);
        }
    }

    void assign(Iterator<T> left, Iterator<T> right)
    {
        size_t count = right - left;
        clear();
        resize(count);
        for (int i = 0; i < count; ++i) {
            new (_arr + i) T(*(left.pointer() + i));
        }
    }

    T &at(size_t index)
    {
        if (index >= _size) {
            return _arr[0];
        } else {
            return _arr[index];
        }
    }

    T &back() { return _arr[_size - 1]; }

    Iterator<T> begin() { return Iterator<T>(_arr); }

    size_t capacity() { return _capacity; }

    Iterator<const T> cbegin() { return Iterator<const T>(_arr); }

    void clear() { resize(0); }

    T *data() { return _arr; }

    template<typename... Args>
    void emplace(Iterator<T> pos, Args &&...args)
    {
        int count = pos - this->begin();
        if (_size == _capacity) {
            reserve(_capacity * 2);
        }
        std::uninitialized_copy(_arr + count, _arr + _size, _arr + count + 1);
        new (_arr + count) T(args...);
        _size++;
    }

    template<typename... Args>
    void emplace(size_t pos, Args &&...args)
    {
        emplace(begin() + pos, args...);
    }

    template<typename... Args>
    void emplace_back(Args &&...args)
    {
        emplace(end(), args...);
    }

    bool empty() { return _size == 0; }

    Iterator<T> end() { return Iterator<T>(_arr + _size); }

    void erase(size_t index)
    {
        if (index >= _size) {
            return;
        }
        for (size_t i = index; i < _size - 1; ++i) {
            _arr[i] = std::move(_arr[i + 1]);
        }
        _size--;
    }

    void erase(size_t leftIndex, size_t rightIndex)
    {
        if (leftIndex >= _size || rightIndex > _size || leftIndex >= rightIndex) {
            return;
        }
        size_t count = rightIndex - leftIndex;

        for (size_t i = leftIndex; i < _size - count; ++i) {
            _arr[i] = std::move(_arr[i + count]);
        }
        _size -= count;
    }

    T &front() { return _arr[0]; }

    void insert(Iterator<T> pos, const T &value) { emplace(pos, value); }

    void insert(Iterator<T> pos, size_t n, const T &value)
    {
        for (size_t i = 0; i < n; i++) {
            emplace(pos + i, value);
        }
    }

    void insert(Iterator<T> pos, Iterator<T> begin, Iterator<T> end)
    {
        size_t n = begin - end;
        for (size_t i = 0; i < n; i++) {
            emplace(pos + i, *(begin + i));
        }
    }

    size_t max_size() { return sizeof(_capacity); }

    void push_back(const T &value) { emplace_back(value); }

    void pop_back()
    {
        if (_size == 0) {
            return;
        }
        _arr[_size - 1].~T();
        _size--;
    }

    ReverseIterator<T> rbegin() { return _arr + _size; }

    ReverseIterator<T> rend() { return _arr; }

    void resize(size_t newSize)
    {
        if (newSize > _capacity) {
            reserve(newSize);
        }
        for (size_t i = _size; i < newSize; i++) {
            new (_arr + i) T();
        }
        for (size_t i = newSize; i < _size; i++) {
            (_arr + i)->~T();
        }
        _size = newSize;
    }

    void reserve(size_t newCapacity)
    {
        if (_capacity <= newCapacity) {
            return;
        }
        T *temp = reinterpret_cast<T *>(new int8_t[sizeof(T) * newCapacity]);
        std::uninitialized_copy(_arr, _arr + _size, temp);
        _capacity = newCapacity;
    }

    int size() { return _size; }

    void swap(MyVector<T> &vect)
    {
        std::swap(_arr, vect._arr);
        std::swap(_capacity, vect._capacity);
        std::swap(_size, vect._size);
    }
};

#endif // MYVECTOR_H
