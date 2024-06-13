#ifndef MYITERATOR_H
#define MYITERATOR_H
#include <cstdio>

template<typename T>
class myIterator {

    T *it;

public:

    explicit myIterator(T *tmp) {
        it = tmp;
    }

    ~myIterator() = default;

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
    myIterator &operator++() {
        ++it;
        return *this;
    }

    myIterator &operator--() {
        --it;
        return *this;
    }

    myIterator operator++(int) {
        return iterator(it++);
    }

    myIterator operator--(int) {
        return iterator(it--);
    }

    // + | -
    myIterator operator+(int n) {
        return iterator(it + n);
    }

    myIterator operator-(size_t n) {
        return iterator(it - n);
    }

    // += | -=
    myIterator &operator+=(size_t n) {
        it += n;
        return *this;
    }

    myIterator &operator-=(size_t n) {
        it -= n;
        return *this;
    }

    // []
    T operator[](size_t n) {
        return it[n];
    }

    bool operator !=(myIterator x) {
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

    // *
    T &operator*() const {
        return *it;
    }

    // ->
    T *operator->() const {
        return  it;
    }

    // ++ | --
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

    // + | -
    reverse_iterator operator+(size_t n) {
        return reverse_iterator(it - n);
    }

    reverse_iterator operator-(size_t n) {
        return reverse_iterator(it + n);
    }

    // += | -=
    reverse_iterator &operator+=(size_t n) {
        it -= n;
        return *this;
    }

    reverse_iterator &operator-=(size_t n) {
        it += n;
        return *this;
    }

    // []
    T operator[](size_t n) {
        return it[n];
    }
};


#endif // MYITERATOR_H
