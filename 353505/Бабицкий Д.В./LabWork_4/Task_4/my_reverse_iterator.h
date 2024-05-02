#ifndef MY_REVERSE_ITERATOR_H
#define MY_REVERSE_ITERATOR_H

#include <cstddef>

template<typename T>
class My_reverse_iterator {
private:
    T* ptr;

public:
    const T *base() const {
        return ptr;
    }
    My_reverse_iterator(T* p);
    ~My_reverse_iterator();
    T& operator*() const;
    T* operator->() const;
    My_reverse_iterator& operator++();
    My_reverse_iterator operator++(int);
    My_reverse_iterator& operator--();
    My_reverse_iterator operator--(int);
    My_reverse_iterator operator+(int n) const;
    My_reverse_iterator operator-(int n) const;
    My_reverse_iterator& operator+=(int n);
    My_reverse_iterator& operator-=(int n);
    T& operator[](int n) const;
    bool operator==(const My_reverse_iterator& other) const;
    bool operator!=(const My_reverse_iterator& other) const;
    ptrdiff_t operator-(const My_reverse_iterator& other) const {
        return other.ptr - ptr;
    }
    using difference_type = std::ptrdiff_t;
};

#endif // MY_REVERSE_ITERATOR_H
