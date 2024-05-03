#ifndef DVECTOR_H
#define DVECTOR_H

#include "iterator.h"
#include "qdebug.h"
#include "qlogging.h"
#include <algorithm>
#include <cstddef>
#include <limits>
#include <stdexcept>

template <typename T>
class Dvector
{
private:
    T* array;
    size_t size;
    size_t capacity;

public:
    explicit Dvector(size_t initial_capacity) : array(new T[initial_capacity]), size(0), capacity(initial_capacity) {}
    Dvector() : array(nullptr), size(0), capacity(0) {}
    ~Dvector() {

        qDebug() << "Destructor called for Dvector at address:" << this;

        qDebug() << "Memory freed for Dvector at address:" << this;



    }


    T& operator[](size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    const T& operator[](size_t index) const {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }
    void push_back(const T& value) {
        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        array[size++] = value;
    }

    void reserve(size_t new_capacity) {
        if (new_capacity > capacity) {
            T* new_array = new T[new_capacity];
            for (size_t i = 0; i < size; ++i) {
                new_array[i] = array[i];
            }
            delete[] array;
            array = new_array;
            capacity = new_capacity;
        }
    }

    void assign(size_t count, const T& value) {
        clear();
        reserve(count);
        std::fill_n(array, count, value);
        size = count;
    }

    void clear() { size = 0; }

    void resize(size_t new_size) {
        if (new_size > size) {
            reserve(new_size);
        }
        size = new_size;
    }

    T& front() { return array[0]; }

    void emplace_back(T&& value) {
        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }
        array[size++] = std::move(value);
    }

    T& back() { return array[size - 1]; }

    void pop_back() {
        if (size > 0) {
            --size;
        }
    }

    bool empty() const { return size == 0; }

    T* data() { return array; }

    void erase(int x) {
        if (x >= 0 && x < size) {
            for (int i = x; i < size - 1; ++i) {
                array[i] = array[i + 1];
            }
            --size;
        }
    }

    T& at(size_t index) {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return array[index];
    }

    size_t Capacity() const { return capacity; }

    size_t max_size() const { return std::numeric_limits<size_t>::max(); }

    void insert(size_t position, const T& value) {
        if (position > size) {
            throw std::out_of_range("Position is out of range.");
        }

        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }

        for (size_t i = size; i > position; --i) {
            array[i] = array[i - 1];
        }

        array[position] = value;
        ++size;
    }

    void emplace(size_t position, T&& value) {
        if (position > size) {
            throw std::out_of_range("Position is out of range.");
        }

        if (size >= capacity) {
            reserve(capacity == 0 ? 1 : capacity * 2);
        }

        for (size_t i = size; i > position; --i) {
            array[i] = std::move(array[i - 1]);
        }

        array[position] = std::move(value);
        ++size;
    }

    size_t Size() const { return size; }

    Iterator<T> begin() { return Iterator<T>(array);
    }

    Iterator<const T> cbegin() const { return Iterator<const T>(array); }

    Iterator<T> end() { return Iterator<T>(array + size); }

    ReverseIterator<T> rbegin() { return ReverseIterator<T>(array + size - 1); }

    ReverseIterator<T> rend() { return ReverseIterator<T>(array - 1); }

    void swap(Dvector<T>& other) {
        std::swap(array, other.array);
        std::swap(size, other.size);
        std::swap(capacity, other.capacity);
    }

};

#endif // DVECTOR_H

