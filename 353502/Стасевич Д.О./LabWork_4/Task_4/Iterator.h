#ifndef TASK4_ITERATOR_H
#define TASK4_ITERATOR_H

#include <cstddef>

template<typename T>
class Iterator {
private:
    T *it;
public:

    explicit Iterator(T *cur)
    {
        it = cur;
    }

    ~Iterator() = default;

    bool operator == (const Iterator& it2)
    {
        return it == it2;
    }

    bool operator != (Iterator it2)
    {
        return it != it2.operator->();
    }

    T operator [] (size_t n)
    {
        return it[n];
    }

    const T *base() const
    {
        return it;
    }

    T &operator*() const
    {
        return *it;
    }

    T *operator->() const
    {
        return it;
    }

    // ++ it
    Iterator &operator++()
    {
        ++it;
        return *this;
    }

    // -- it
    Iterator &operator--()
    {
        -- it;
        return *this;
    }

    // it ++ - create copy first
    Iterator operator ++(int)
    {
        return Iterator(it++);
    }

    // it --
    Iterator operator --(int)
    {
        return Iterator(it--);
    }

    Iterator operator +(int n)
    {
        return Iterator(it + n);
    }

    Iterator operator -(int n)
    {
        return Iterator(it - n);
    }

    // it += 3
    Iterator &operator +=(int n)
    {
        it += n;
        return *this;
    }

    // it -= 3
    Iterator &operator -=(size_t n)
    {
        it -= 3;
        return *this;
    }
};

#endif //TASK4_ITERATOR_H
