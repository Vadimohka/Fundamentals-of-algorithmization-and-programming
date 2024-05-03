#ifndef MY_ITERATOR_H
#define MY_ITERATOR_H

#include <cstddef>

template<typename T>
class My_iterator {
private:
    T* ptr;

public:
    const T *base() const {
        return ptr;
    }
    My_iterator(T* p) : ptr(p) {}
    ~My_iterator() = default;
    T& operator*() const;
    T* operator->() const;
    My_iterator& operator++();
    My_iterator operator++(int);
    My_iterator& operator--();
    My_iterator& operator--(int);
    My_iterator operator+(int n) const;
    My_iterator operator-(int n) const;
    My_iterator& operator+=(int n);
    My_iterator& operator-=(int n);
    T& operator[](int n) const;
    bool operator==(const My_iterator& other) const;
    bool operator!=(const My_iterator& other) const;
    ptrdiff_t operator-(const My_iterator& other) const {
        return ptr - other.ptr;
    }
    using difference_type = std::ptrdiff_t;
};

#endif // MY_ITERATOR_H
