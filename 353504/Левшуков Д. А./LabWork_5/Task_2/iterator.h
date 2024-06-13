#ifndef iterator_H
#define iterator_H

template<typename T>
class iterator
{
    T *it;

public:
    iterator(T *v)
    {
        it=v;
    }

    const T *base() const
    {
        return it;
    }

    const T *get() const
    {
        return it;
    }

    T &operator*() const
    {
        return *it;
    }

    iterator operator+(unsigned value)
    {
        return iterator(it + value);
    }
};

template<typename T>
class ReverseIterator
{
    T *it;

public:
    ReverseIterator(T *temp)
    {
        it = temp;
    }

    const T *base() const
    {
        return it;
    }

    const T *get() const
    {
        return it;
    }

    T &operator*() const
    {
        return *it;
    }

    ReverseIterator operator+(unsigned value)
    {
        return ReverseIterator(it - value);
    }

};

#endif // iterator_H
