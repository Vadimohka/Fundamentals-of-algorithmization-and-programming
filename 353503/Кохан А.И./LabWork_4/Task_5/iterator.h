#ifndef ITERATOR_H
#define ITERATOR_H

#include <cstddef>
template<typename T>
class Iterator
{
    T *ptr;

public:
    explicit Iterator(T *temp)
        : ptr(temp)
    {}
    ~Iterator() = default;

    const T *base() const { return ptr; }

    T &operator*() const { return *ptr; }

    T *operator->() const { return ptr; }

    Iterator &operator++()
    {
        ++ptr;
        return *this;
    }

    Iterator &operator--()
    {
        --ptr;
        return *this;
    }

    const Iterator operator++(int) { return Iterator(++ptr); }

    const Iterator operator--(int) { return Iterator(--ptr); }

    Iterator operator+(int n) { return Iterator(ptr + n); }

    Iterator operator-(size_t n) { return Iterator(ptr - n); }

    Iterator &operator+=(size_t n)
    {
        ptr += n;
        return *this;
    }

    Iterator &operator-=(size_t n)
    {
        ptr -= n;
        return *this;
    }

    T operator[](size_t n) { return ptr[n]; }

    bool operator!=(Iterator x) { return ptr != x.operator->(); }
};
#endif // ITERATOR_H
