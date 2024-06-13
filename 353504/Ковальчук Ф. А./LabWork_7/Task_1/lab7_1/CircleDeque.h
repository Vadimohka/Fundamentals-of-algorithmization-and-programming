#ifndef CIRCLEDEQUE_H
#define CIRCLEDEQUE_H

#include <cstddef>
#include <cstdint>
#include <iterator>

constexpr size_t BLOCK_SIZE = 8;
constexpr size_t INITAL_CAPASITY = 2;
constexpr int64_t NOTHING = -1;

template<typename T>
class DequeIterator;

template<typename T>
class CircleDeque
{
    void reallocate();

public:
    using iterator = DequeIterator<T>;

    CircleDeque();
    ~CircleDeque();
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

private:
    T **data;
    size_t _size;     // кол-во элементов
    size_t _capasity; // кол-во блоков может вместить
    int64_t _frontBlock; // номер подмассива в котором находится первый элемент
    int64_t _frontIndex; // индекс первого элемента в подмассиве
    int64_t _backBlock; // номер подмассива в котором находится последний элемент
    int64_t _backIndex; // индекс последнего элемента в подмассиве
};

template<typename T>
class DequeIterator
{
public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::random_access_iterator_tag;

    DequeIterator(CircleDeque<T> *deque, size_t index)
        : deque(deque)
        , index(index)
    {}

    T &operator*() { return (*deque)[index]; }

    const T &operator*() const { return (*deque)[index]; }

    DequeIterator operator++()
    {
        index = (index + 1) % (deque->size());
        return *this;
    }

    DequeIterator operator--()
    {
        index = (index - 1 + deque->size()) % (deque->size());
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

private:
    CircleDeque<T> *deque;
    size_t index;
};

#endif // CIRCLEDEQUE_H
