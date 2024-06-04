#ifndef DEQUE_H
#define DEQUE_H

#include <cstddef>
#include <cstdint>
#include <iterator>

template<typename T>
class DequeIterator;

template<typename T>
class Deque
{
private:
    static const size_t BLOCK_SIZE = 8;
    static const size_t INITAL_CAPASITY = 2;
    static const int64_t NOTHING = -1;

    T **data;
    size_t _size;     // кол-во элементов
    size_t _capasity; // кол-во блоков может вместить
    int64_t _frontBlock; // номер подмассива в котором находится первый элемент
    int64_t _frontIndex; // индекс первого элемента в подмассиве
    int64_t _backBlock; // номер подмассива в котором находится последний элемент
    int64_t _backIndex; // индекс последнего элемента в подмассиве

    void reallocate();

public:
    using iterator = DequeIterator<T>;

    Deque();
    ~Deque();
    void push_back(T data);
    void push_front(T data);

    const T &operator[](size_t index) const;
    T &operator[](size_t index);
    const T &at(size_t index) const;

    size_t size() const;
    bool empty() const;
    void pop_back();
    void pop_front();
    void clear();

    DequeIterator<T> begin();
    DequeIterator<T> end();
};

template<typename T>
class DequeIterator
{
private:
    Deque<T> *deque;
    size_t index;

public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::random_access_iterator_tag;

    DequeIterator(Deque<T> *deque, size_t index)
        : deque(deque)
        , index(index)
    {}

    T &operator*() { return deque[index]; }

    const T &operator*() const { return deque[index]; }

    DequeIterator operator++()
    {
        ++index;
        return *this;
    }

    DequeIterator operator--()
    {
        --index;
        return *this;
    }

    const DequeIterator operator++(int)
    {
        DequeIterator temp = *this;
        ++index;
        return temp;
    }

    const DequeIterator operator--(int)
    {
        DequeIterator temp = *this;
        --index;
        return temp;
    }

    DequeIterator operator+(difference_type n) const { return DequeIterator(deque, index + n); }

    DequeIterator operator-(difference_type n) const { return DequeIterator(deque, index - n); }

    difference_type operator-(const DequeIterator &other) { return index - other.index; }

    bool operator==(const DequeIterator &other) const { return index == other.index; }

    bool operator!=(const DequeIterator &other) const { return index != other.index; }

    bool operator<(const DequeIterator &other) const { return index < other.index; }

    bool operator>(const DequeIterator &other) const { return index > other.index; }

    bool operator<=(const DequeIterator &other) const { return index <= other.index; }

    bool operator>=(const DequeIterator &other) const { return index >= other.index; }
};

#endif // DEQUE_H
