#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
class Iterator
{
    T *iter;

public:
    explicit Iterator(T *temp)
    {
        iter = temp;
    }

    const T *base() const
    {
        return iter;
    }

    T &operator*() const
    {
        return *iter;
    }

    T *operator->() const
    {
        return iter;
    }

    Iterator &operator++()
    {
        ++iter;
        return *this;
    }

    Iterator &operator--()
    {
        --iter;
        return *this;
    }

    Iterator &operator++(int)
    {
        return Iterator(iter++);
    }

    Iterator &operator--(int)
    {
        return Iterator(iter--);
    }

    Iterator operator+(int value)
    {
        return Iterator(iter + value);
    }

    Iterator operator-(int value)
    {
        return Iterator(iter - value);
    }

    Iterator &operator+=(int value)
    {
        iter += value;
        return *this;
    }

    Iterator &operator-=(int value)
    {
        iter -= value;
        return *this;
    }

    T operator[](int index)
    {
        return iter[index];
    }

    bool operator==(Iterator &other)
    {
        return iter == other.operator->();
    }

    bool operator!=(Iterator &other)
    {
        return iter != other.operator->();
    }
};

template<typename T>
class ReverseIterator
{
    T *iter;

public:
    explicit ReverseIterator(T *temp)
    {
        iter = temp;
    }

    ~ReverseIterator();

    const T *base() const
    {
        return iter;
    }

    T &operator*() const
    {
        return *iter;
    }

    T *operator->() const
    {
        return iter;
    }

    ReverseIterator &operator++()
    {
        --iter;
        return *this;
    }

    ReverseIterator &operator--()
    {
        ++iter;
        return *this;
    }

    ReverseIterator &operator++(int)
    {
        return Iterator(iter--);
    }

    ReverseIterator &operator--(int)
    {
        return Iterator(iter++);
    }

    ReverseIterator operator+(int value)
    {
        return Iterator(iter - value);
    }

    ReverseIterator operator-(int value)
    {
        return Iterator(iter + value);
    }

    ReverseIterator &operator+=(int value)
    {
        iter -= value;
        return *this;
    }

    ReverseIterator &operator-=(int value)
    {
        iter += value;
        return *this;
    }

    T operator[](int index)
    {
        return iter[index];
    }

    bool operator==(ReverseIterator &other)
    {
        return iter == other.operator->();
    }

    bool operator!=(ReverseIterator &other)
    {
        return iter != other.operator->();
    }
};

#endif // ITERATOR_H