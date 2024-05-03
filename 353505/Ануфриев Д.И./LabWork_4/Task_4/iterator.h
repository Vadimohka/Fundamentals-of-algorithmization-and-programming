#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstdio>

template<typename T>
class Iterator {

    T *it;

public:

    explicit Iterator(T *tmp) {
        it = tmp;
    }

    ~Iterator() = default;

    const T *base() const {
        return it;
    }

    // *
    T &operator*() const {
        return *it;
    }

    // ->
    T *operator->() const {
        return it;
    }

    // ++ | --
    Iterator &operator++() {
        ++it;
        return *this;
    }

    Iterator &operator--() {
        --it;
        return *this;
    }

    Iterator operator++(int) {
        return Iterator(it++);
    }

    Iterator operator--(int) {
        return Iterator(it--);
    }

    // + | -
    Iterator operator+(int n) {
        return Iterator(it + n);
    }

    Iterator operator-(size_t n) {
        return Iterator(it - n);
    }

    // += | -=
    Iterator &operator+=(size_t n) {
        it += n;
        return *this;
    }

    Iterator &operator-=(size_t n) {
        it -= n;
        return *this;
    }

    // []
    T operator[](size_t n) {
        return it[n];
    }

    bool operator !=(Iterator x) {
        return it != x.operator->();
    }

};

template<typename T>
class RIterator {

    T *it;

public:

    explicit RIterator(T *tmp) {
        it = tmp;
    }

    ~RIterator() = default;

    const T &base() const {
        return *it;
    }

    // *
    T &operator*() const {
        return *it;
    }

    // ->
    T *operator->() const {
        return  it;
    }

    // ++ | --
    RIterator &operator++() {
        --it;
        return *this;
    }

    RIterator &operator--() {
        ++it;
        return *this;
    }

    RIterator operator++(int) {
        return RIterator(it--);
    }

    RIterator operator--(int) {
        return RIterator(it++);
    }

    // + | -
    RIterator operator+(size_t n) {
        return RIterator(it - n);
    }

    RIterator operator-(size_t n) {
        return RIterator(it + n);
    }

    // += | -=
    RIterator &operator+=(size_t n) {
        it -= n;
        return *this;
    }

    RIterator &operator-=(size_t n) {
        it += n;
        return *this;
    }

    // []
    T operator[](size_t n) {
        return it[n];
    }

};


#endif
