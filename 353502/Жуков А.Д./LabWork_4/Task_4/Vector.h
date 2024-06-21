#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <stdexcept>
#include <memory>
#include <iterator>

template<typename T>
class Vector {
public:
    // Итератор для Vector
    class Iterator : public std::iterator<std::random_access_iterator_tag, T> {
    public:
        Iterator(T* ptr) : ptr(ptr) {}

        T& operator*() const { return *ptr; }
        T* operator->() { return ptr; }
        Iterator& operator++() { ++ptr; return *this; }
        Iterator operator++(int) { Iterator tmp = *this; ++(*this); return tmp; }
        Iterator& operator--() { --ptr; return *this; }
        Iterator operator--(int) { Iterator tmp = *this; --(*this); return tmp; }
        Iterator operator+(int n) const { return Iterator(ptr + n); }
        Iterator operator-(int n) const { return Iterator(ptr - n); }
        int operator-(const Iterator& other) const { return ptr - other.ptr; }
        bool operator==(const Iterator& other) const { return ptr == other.ptr; }
        bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
        bool operator<(const Iterator& other) const { return ptr < other.ptr; }
        bool operator<=(const Iterator& other) const { return ptr <= other.ptr; }
        bool operator>(const Iterator& other) const { return ptr > other.ptr; }
        bool operator>=(const Iterator& other) const { return ptr >= other.ptr; }

    private:
        T* ptr;
    };

    Vector() : _size(0), _capacity(1), _data(new T[1]) {}
    ~Vector() { delete[] _data; }

    // Методы Vector
    void assign(size_t count, const T& value) {
        clear();
        reserve(count);
        for (size_t i = 0; i < count; ++i) {
            new(_data + i) T(value);
        }
        _size = count;
    }

    T& at(size_t pos) {
        if (pos >= _size) throw std::out_of_range("Index out of range");
        return _data[pos];
    }

    T& back() {
        if (_size == 0) throw std::out_of_range("Vector is empty");
        return _data[_size - 1];
    }

    Iterator begin() { return Iterator(_data); }

    size_t capacity() const { return _capacity; }

    Iterator cbegin() const { return Iterator(_data); }

    void clear() {
        for (size_t i = 0; i < _size; ++i) {
            _data[i].~T();
        }
        _size = 0;
    }

    T* data() { return _data; }

    template<typename... Args>
    void emplace(size_t pos, Args&&... args) {
        if (pos > _size) throw std::out_of_range("Index out of range");
        if (_size == _capacity) reserve(_capacity * 2);
        for (size_t i = _size; i > pos; --i) {
            new(_data + i) T(std::move(_data[i - 1]));
            _data[i - 1].~T();
        }
        new(_data + pos) T(std::forward<Args>(args)...);
        ++_size;
    }

    template<typename... Args>
    void emplace_back(Args&&... args) {
        if (_size == _capacity) reserve(_capacity * 2);
        new(_data + _size) T(std::forward<Args>(args)...);
        ++_size;
    }

    bool empty() const { return _size == 0; }

    Iterator end() { return Iterator(_data + _size); }

    void erase(size_t pos) {
        if (pos >= _size) throw std::out_of_range("Index out of range");
        _data[pos].~T();
        for (size_t i = pos; i < _size - 1; ++i) {
            new(_data + i) T(std::move(_data[i + 1]));
            _data[i + 1].~T();
        }
        --_size;
    }

    T& front() {
        if (_size == 0) throw std::out_of_range("Vector is empty");
        return _data[0];
    }

    void insert(size_t pos, const T& value) {
        if (pos > _size) throw std::out_of_range("Index out of range");
        if (_size == _capacity) reserve(_capacity * 2);
        for (size_t i = _size; i > pos; --i) {
            new(_data + i) T(std::move(_data[i - 1]));
            _data[i - 1].~T();
        }
        new(_data + pos) T(value);
        ++_size;
    }

    size_t max_size() const { return std::numeric_limits<size_t>::max(); }

    void pop_back() {
        if (_size == 0) throw std::out_of_range("Vector is empty");
        _data[_size - 1].~T();
        --_size;
    }

    void push_back(const T& value) {
        if (_size == _capacity) reserve(_capacity * 2);
        new(_data + _size) T(value);
        ++_size;
    }

    Iterator rbegin() { return Iterator(_data + _size - 1); }

    Iterator rend() { return Iterator(_data - 1); }

    void reserve(size_t new_capacity) {
        if (new_capacity > _capacity) {
            T* new_data = new T[new_capacity];
            for (size_t i = 0; i < _size; ++i) {
                new(new_data + i) T(std::move(_data[i]));
                _data[i].~T();
            }
            delete[] _data;
            _data = new_data;
            _capacity = new_capacity;
        }
    }

    void resize(size_t new_size) {
        if (new_size > _capacity) reserve(new_size);
        for (size_t i = _size; i < new_size; ++i) {
            new(_data + i) T();
        }
        for (size_t i = new_size; i < _size; ++i) {
            _data[i].~T();
        }
        _size = new_size;
    }

    size_t size() const { return _size; }

    void swap(Vector& other) {
        std::swap(_data, other.data());
        std::swap(_size, other.size());
        std::swap(_capacity, other.capacity());
    }

private:
    T* _data;
    size_t _size;
    size_t _capacity;
};

#endif // VECTOR_H
