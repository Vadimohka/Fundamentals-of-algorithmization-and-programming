#ifndef TASK4_REVERSEITERATOR_H
#define TASK4_REVERSEITERATOR_H

#include <cstddef>

template<typename T>
class ReverseIterator {
private:
    T *it;
public:

    explicit ReverseIterator(T *cur)
    {
        it = cur;
    }

    ~ ReverseIterator() = default;

    bool operator == (const ReverseIterator& it2)
    {
        return it == it2;
    }

    bool operator != ( ReverseIterator it2)
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
    ReverseIterator &operator++()
    {
        --it;
        return *this;
    }

    // -- it
    ReverseIterator &operator--()
    {
        ++ it;
        return *this;
    }

    // it ++ - create copy first
    ReverseIterator operator ++(int)
    {
        return ReverseIterator(it--);
    }

    // it --
    ReverseIterator operator --(int)
    {
        return ReverseIterator(it++);
    }

    ReverseIterator operator +(int n)
    {
        return ReverseIterator(it - n);
    }

    ReverseIterator operator -(int n)
    {
        return ReverseIterator(it + n);
    }

    // it += 3
    ReverseIterator &operator +=(int n)
    {
        it -= n;
        return *this;
    }

    // it -= 3
    ReverseIterator &operator -=(size_t n)
    {
        it += n;
        return *this;
    }
};

#endif //TASK4_REVERSEITERATOR_H
