#ifndef ITERATOR_H
#define ITERATOR_H

//random access iterator
#include <cstddef>
template<typename T>
class Iterator
{
public:
    Iterator(T *ptr)
        : ptr(ptr){};

    T &operator*() { return *ptr; }

    Iterator &operator++()
    {
        ++ptr;
        return *this;
    }

    Iterator operator++(int) //(int) для различия пост и пре
    {
        Iterator temp = *this;
        ++ptr;
        return temp;
    }

    Iterator &operator--()
    {
        --ptr;
        return *this;
    }

    Iterator operator--(int)
    {
        Iterator temp = *this;
        --ptr;
        return temp;
    }

    bool operator==(/*первый конст - константная ссылка*/ const Iterator &other)
        /*второй - метод не изменяет состояние объекта*/ const
    {
        return ptr == other.ptr;
    }

    bool operator!=(const Iterator &other) const { return ptr != other.ptr; }

    //смещенные итераторы
    Iterator operator+(int n) const { return Iterator(ptr + n); }

    Iterator &operator+=(int n) const
    {
        ptr += n;
        return *this;
    }

    Iterator operator-(int n) const { return Iterator(ptr - n); }

    Iterator operator-=(int n) const
    {
        ptr -= n;
        return *this;
    }

    ptrdiff_t operator-(const Iterator &other) const { return ptr - other.ptr; }

    //оператор индексирования []
    T &operator[](int n) const { return *(ptr + n); }

    //операторы сравнения

    bool operator<(const Iterator &other) const { return ptr < other.ptr; }

    bool operator>(const Iterator &other) const { return ptr > other.ptr; }

    bool operator<=(const Iterator &other) const { return ptr <= other.ptr; }

    bool operator>=(const Iterator &other) const { return ptr >= other.ptr; }

private:
    T *ptr; //хранение адреса элемента вектора
};

//обратный итератор
template<typename T>
class ReverseIterator
{
    ReverseIterator(T *ptr)
        : ptr(ptr)
    {}

    T &operator*() { return *ptr; }

    ReverseIterator &operator++()
    {
        --ptr;
        return *this;
    }

    ReverseIterator operator++(int)
    {
        ReverseIterator temp = *this;
        --ptr;
        return temp;
    }

    ReverseIterator &operator--()
    {
        ++ptr;
        return *this;
    }

    ReverseIterator operator--(int)
    {
        ReverseIterator temp = *this;
        ++ptr;
        return temp;
    }

    bool operator==(const ReverseIterator &other) const { return ptr == other.ptr; }

    bool operator!=(const ReverseIterator &other) const { return ptr != other.ptr; }

    ReverseIterator operator+(int n) const { return ReverseIterator(ptr - n); }

    ReverseIterator &operator+=(int n)
    {
        ptr -= n;
        return *this;
    }

    ReverseIterator operator-(int n) const { return ReverseIterator(ptr + n); }

    ReverseIterator &operator-=(int n)
    {
        ptr += n;
        return *this;
    }

    T &operator[](int n) const { return *(ptr - n); }

    bool operator<(const ReverseIterator &other) const { return ptr > other.ptr; }

    bool operator>(const ReverseIterator &other) const { return ptr < other.ptr; }

    bool operator<=(const ReverseIterator &other) const { return ptr >= other.ptr; }

    bool operator>=(const ReverseIterator &other) const { return ptr <= other.ptr; }

private:
    T *ptr;
};

//константный итератор
template<typename T>
class ConstIterator
{
public:
    ConstIterator(const T *ptr)
        : ptr(ptr)
    {}

    const T &operator*() const { return *ptr; }

    ConstIterator &operator++()
    {
        ++ptr;
        return *this;
    }

    ConstIterator operator++(int)
    {
        ConstIterator temp = *this;
        ++ptr;
        return temp;
    }

    ConstIterator &operator--()
    {
        --ptr;
        return *this;
    }

    ConstIterator operator--(int)
    {
        ConstIterator temp = *this;
        --ptr;
        return temp;
    }

    bool operator==(const ConstIterator &other) const { return ptr == other.ptr; }

    bool operator!=(const ConstIterator &other) const { return ptr != other.ptr; }

    ConstIterator operator+(int n) const { return ConstIterator(ptr + n); }

    ConstIterator &operator+=(int n)
    {
        ptr += n;
        return *this;
    }

    ConstIterator operator-(int n) const { return ConstIterator(ptr - n); }

    ConstIterator &operator-=(int n)
    {
        ptr -= n;
        return *this;
    }

    const T &operator[](int n) const { return *(ptr + n); }

    bool operator<(const ConstIterator &other) const { return ptr < other.ptr; }

    bool operator>(const ConstIterator &other) const { return ptr > other.ptr; }

    bool operator<=(const ConstIterator &other) const { return ptr <= other.ptr; }

    bool operator>=(const ConstIterator &other) const { return ptr >= other.ptr; }

private:
    const T *ptr;
};

//обратный константный итератор
template<typename T>
class ConstReverseIterator
{
public:
    ConstReverseIterator(const T *ptr)
        : ptr(ptr)
    {}

    const T &operator*() const { return *ptr; }

    ConstReverseIterator &operator++()
    {
        --ptr;
        return *this;
    }

    ConstReverseIterator operator++(int)
    {
        ConstReverseIterator temp = *this;
        --ptr;
        return temp;
    }

    ConstReverseIterator &operator--()
    {
        ++ptr;
        return *this;
    }

    ConstReverseIterator operator--(int)
    {
        ConstReverseIterator temp = *this;
        ++ptr;
        return temp;
    }

    bool operator==(const ConstReverseIterator &other) const { return ptr == other.ptr; }

    bool operator!=(const ConstReverseIterator &other) const { return ptr != other.ptr; }

    ConstReverseIterator operator+(int n) const { return ConstReverseIterator(ptr - n); }

    ConstReverseIterator &operator+=(int n)
    {
        ptr -= n;
        return *this;
    }

    ConstReverseIterator operator-(int n) const { return ConstReverseIterator(ptr + n); }

    ConstReverseIterator &operator-=(int n)
    {
        ptr += n;
        return *this;
    }
    const T &operator[](int n) const { return *(ptr - n); }

    bool operator<(const ConstReverseIterator &other) const { return ptr > other.ptr; }

    bool operator>(const ConstReverseIterator &other) const { return ptr < other.ptr; }

    bool operator<=(const ConstReverseIterator &other) const { return ptr >= other.ptr; }

    bool operator>=(const ConstReverseIterator &other) const { return ptr <= other.ptr; }

private:
    const T *ptr;
};

#endif // ITERATOR_H
