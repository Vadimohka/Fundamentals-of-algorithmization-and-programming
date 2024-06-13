#ifndef ITERATOR_H
#define ITERATOR_H

template<typename T>
class Iterator
{
    T *iterator;

public:
    explicit Iterator(T *temp) { iterator = temp; }

    const T *base() const { return iterator; }

    T &operator*() const { return *iterator; }

    T *operator->() const { return iterator; }

    Iterator &operator++()
    {
        ++iterator;
        return *this;
    }

    Iterator &operator--()
    {
        --iterator;
        return *this;
    }

    Iterator &operator++(int) { return Iterator(iterator++); }

    Iterator &operator--(int) { return Iterator(iterator--); }

    Iterator operator+(int value) { return Iterator(iterator + value); }

    Iterator operator-(int value) { return Iterator(iterator - value); }

    Iterator &operator+=(int value)
    {
        iterator += value;
        return *this;
    }

    Iterator &operator-=(int value)
    {
        iterator -= value;
        return *this;
    }

    T operator[](int index) { return iterator[index]; }

    bool operator==(Iterator &other) { return iterator == other.operator->(); }

    bool operator!=(Iterator &other) { return iterator != other.operator->(); }
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
