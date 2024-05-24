#ifndef VECTOR_H
#define VECTOR_H

#include "qdebug.h"
#include "qlogging.h"

#include "vectoriterator.h"
#include "vectorriterator.h"
#include <limits>
#include <utility>

template<typename T>
class Vector {
private:
    T *elements = nullptr;
    size_t sz = 0;
    size_t capacity_ = 0;

public:
    typedef VectorIterator<T> iterator;
    typedef VectorRIterator<T> riterator;

    Vector() : elements(nullptr), sz(0), capacity_(0) {}

    explicit Vector(size_t n) : sz(n), capacity_(n) {
        elements = new T[capacity_];
    }

    Vector(size_t n, const T &val) : sz(n), capacity_(n) {
        elements = new T[capacity_];
        for (size_t i = 0; i < sz; ++i) {
            elements[i] = val;
        }
    }

    ~Vector() {
        clear();
    }

    void assign(size_t count, const T &value) {
        clear();
        sz = count;
        if (sz > capacity_) {
            capacity_ = sz;
            delete[] elements;
            elements = new T[capacity_];
        }
        for (size_t i = 0; i < sz; ++i) {
            elements[i] = value;
        }
    }

    T &at(size_t pos) {
        return elements[pos];
    }

    T &back() {
        return elements[sz - 1];
    }

    iterator begin() {
        return iterator(elements);
    }

    [[nodiscard]] size_t capacity() const {
        return capacity_;
    }

    const iterator cbegin() const {
        return iterator(elements);
    }

    void clear() {
        //        delete[] elements;
        sz = 0;
        capacity_ = 0;
        elements = nullptr;
    }

    T *data() {
        return elements;
    }

    iterator emplace(iterator pos, T el) {
        size_t index = pos - begin();
        if (sz >= capacity_) {
            reserve(sz + 1);
        }
        for (size_t i = capacity_ - 1; i > index; --i) {
            elements[i] = elements[i - 1];
        }
        //        new(&elements[index]) T(el);
        elements[index] = el;
        ++sz;
        return iterator(&elements[index]);
    }

    void emplace_back(T el) {
        emplace(end(), el);
    }

    [[nodiscard]] bool empty() const {
        return sz == 0;
    }

    iterator end() {
        return iterator(elements) + sz;
    }

    void erase(iterator pos) {
        erase(pos, pos + 1);
    }

    void erase(iterator first, iterator last) {
        size_t numToDelete = last - first;
        for (iterator it = first; it != end() - numToDelete; ++it) {
            *it = *(it + numToDelete);
        }
        sz -= numToDelete;
    }

    T &front() {
        return elements[0];
    }

    void insert(iterator pos, const T &value) {
        emplace(pos, value);
    }

    void insert(iterator pos, size_t count, const T &value) {
        size_t index = pos - begin();
        if (sz + count > capacity_) {
            reserve(sz + count);
        }
        for (size_t i = sz + count - 1; i >= index + count; --i) {
            elements[i] = elements[i - count];
        }
        for (size_t i = 0; i < count; ++i) {
            elements[index + i] = value;
        }
        sz += count;
    }

    [[nodiscard]] size_t max_size() const {
        return std::numeric_limits<size_t>::max() / sizeof(T);
    }

    void pop_back() {
        --sz;
        elements[sz].~T();
    }

    void push_back(const T &value) {
        emplace_back(value);
    }

    riterator rbegin() {
        return riterator(elements) + sz - 1;
    }

    riterator rend() {
        return riterator(elements) - 1;
    }

    void reserve(size_t new_cap) {
        if (new_cap > capacity_) {
            T *new_elements = new T[new_cap];
            for (size_t i = 0; i < sz; ++i) {
                new_elements[i] = std::move(elements[i]);
            }
            delete[] elements;
            elements = new_elements;
            capacity_ = new_cap;
        }
    }

    void resize(size_t count) {
        if (count < sz) {
            erase(begin() + count, end());
        } else if (count > sz) {
            if (count > capacity_) {
                reserve(count);
            }
            for (size_t i = sz; i < count; ++i) {
                //                new(&elements[i]) T();
                elements[i] = T();
            }
        }
        sz = count;
    }

    [[nodiscard]] size_t size() const {
        return sz;
    }

    void swap(Vector<T> &other) {
        {
            auto tmp = elements;
            elements = other.elements;
            other.elements = tmp;
        }
        {
            auto tmp = sz;
            sz = other.sz;
            other.sz = tmp;
        }
        {
            auto tmp = capacity_;
            capacity_ = other.capacity_;
            other.capacity_ = tmp;
        }
    }
};

#endif // VECTOR_H
