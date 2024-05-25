#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstdio>

template<typename T>
class iterator {
    T *it;
public:
    explicit iterator(T *tmp) {
        it = tmp;
    }
    ~iterator() = default;
    const T *base() const {
        return it;
    }
    T &operator*() const {
        return *it;
    }
    T *operator->() const {
        return it;
    }
    iterator &operator++() {
        ++it;
        return *this;
    }
    iterator &operator--() {
        --it;
        return *this;
    }
    iterator operator++(int) {
        return iterator(it++);
    }
    iterator operator--(int) {
        return iterator(it--);
    }
    iterator operator+(int n) {
        return iterator(it + n);
    }
    iterator operator-(size_t n) {
        return iterator(it - n);
    }
    iterator &operator+=(size_t n) {
        it += n;
        return *this;
    }
    iterator &operator-=(size_t n) {
        it -= n;
        return *this;
    }
    T operator[](size_t n) {
        return it[n];
    }
    bool operator !=(iterator x) {
        return it != x.operator->();
    }
};

template<typename T>
class reverse_iterator {
    T *it;
public:
    explicit reverse_iterator(T *tmp) {
        it = tmp;
    }
    ~reverse_iterator() = default;
    const T &base() const {
        return *it;
    }
    T &operator*() const {
        return *it;
    }
    T *operator->() const {
        return  it;
    }
    reverse_iterator &operator++() {
        --it;
        return *this;
    }
    reverse_iterator &operator--() {
        ++it;
        return *this;
    }
    reverse_iterator operator++(int) {
        return reverse_iterator(it--);
    }
    reverse_iterator operator--(int) {
        return reverse_iterator(it++);
    }
    reverse_iterator operator+(size_t n) {
        return reverse_iterator(it - n);
    }
    reverse_iterator operator-(size_t n) {
        return reverse_iterator(it + n);
    }
    reverse_iterator &operator+=(size_t n) {
        it -= n;
        return *this;
    }
    reverse_iterator &operator-=(size_t n) {
        it += n;
        return *this;
    }
    T operator[](size_t n) {
        return it[n];
    }
};

#endif // ITERATOR_H
