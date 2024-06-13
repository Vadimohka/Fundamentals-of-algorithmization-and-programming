#ifndef DEQUE_H
#define DEQUE_H

#include <cstddef>
#include <cstdint>
#include <iterator>
#include <utility>

template<typename T>
class DequeIterator;

template<typename T>
class Deque
{
private:
    T **data;

    size_t _size;     // кол-во элементов
    size_t _capasity; // кол-во блоков может вместить
    int64_t _frontBlock; // номер подмассива в котором находится первый элемент
    int64_t _frontIndex; // индекс первого элемента в подмассиве
    int64_t _backBlock; // номер подмассива в котором находится последний элемент
    int64_t _backIndex; // индекс последнего элемента в подмассиве

    void reallocate()
    {
        size_t newCap = (_capasity * 2);
        T **newData = reinterpret_cast<T **>(new int8_t[sizeof(T *) * newCap]);

        size_t start = _frontBlock;
        for (size_t i = 0; i < _capasity; ++i) {
            newData[i] = data[start];
            start = (start + 1) % _capasity;
        }

        for (size_t i = _capasity; i < newCap; ++i) {
            newData[i] = reinterpret_cast<T *>(new int8_t[sizeof(T) * 8]);
        }

        delete[] reinterpret_cast<int8_t *>(data);
        data = newData;
        _capasity = newCap;
        _frontBlock = 0;
        _backBlock = (_size - 1) / 8;
    }

public:
    using iterator = DequeIterator<T>;

    Deque()
        : _size(0)
        , _capasity(2)
        , _frontBlock(-1)
        , _frontIndex(-1)
        , _backBlock(-1)
        , _backIndex(-1)
    {
        data = reinterpret_cast<T **>(new char *[_capasity * sizeof(T *)]);

        for (size_t i = 0; i < _capasity; ++i) {
            data[i] = reinterpret_cast<T *>(new char[8 * sizeof(T)]);
        }
    }

    ~Deque()
    {
        for (size_t i = 0; i < _size; ++i) {
            data[(_frontBlock + (i + _frontIndex) / 8) % _capasity][(i + _frontIndex) % 8].~T();
        }

        for (size_t i = 0; i < _capasity; ++i) {
            delete[] reinterpret_cast<int8_t *>(data[i]);
        }

        delete[] reinterpret_cast<int8_t *>(data);
    }
    void push_back(T value)
    {
        if ((_size == _capasity * 8)
            || (((static_cast<int64_t>((_backBlock + 1) % _capasity)) == _frontBlock)
                && _backIndex == 7)) {
            reallocate();
        }

        if (_frontBlock == -1) {
            _frontBlock = 0;
            _frontIndex = 0;
            _backBlock = 0;
            _backIndex = 0;
        } else {
            _backIndex = (_backIndex + 1) % 8;
            if (_backIndex == 0) {
                _backBlock = (_backBlock + 1) % _capasity;
            }
        }

        new (&data[_backBlock][_backIndex]) T(std::move(value));
        ++_size;
    }

    void push_front(T value)
    {
        if (_size == _capasity * 8
            || (((static_cast<int64_t>((_frontBlock - 1 + _capasity) % _capasity)) == _backBlock)
                && _frontIndex == 0)) {
            reallocate();
        }

        if (_frontBlock == -1) {
            _frontBlock = 0;
            _frontIndex = 0;
            _backBlock = 0;
            _backIndex = 0;
        } else {
            _frontIndex = (_frontIndex + 7) % 8;
            if (_frontIndex == 7) {
                _frontBlock = (_frontBlock - 1 + _capasity) % _capasity;
            }
        }

        new (&data[_frontBlock][_frontIndex]) T(std::move(value));
        ++_size;
    }

    T &operator[](size_t index)
    {
        index = index % _size;

        return data[(_frontBlock + (index + _frontIndex) / 8) % _capasity][(index + _frontIndex) % 8];
    }

    const T &operator[](size_t index) const
    {
        index = index % _size;

        return data[(_frontBlock + (index + _frontIndex) / 8) % _capasity][(index + _frontIndex) % 8];
    }

    const T &at(size_t index) const
    {
        index = index % _size;

        return data[(_frontBlock + (index + _frontIndex) / 8) % _capasity][(index + _frontIndex) % 8];
    }

    size_t size() const { return _size; }

    bool empty() const { return _size == 0; }

    void pop_back()
    {
        if (empty()) {
            return;
        }

        data[_backBlock][_backIndex].~T();
        _backIndex = (_backIndex + 7) % 8;
        if (_backIndex == 7) {
            _backBlock = (_backBlock - 1 + _capasity) % _capasity;
        }

        --_size;
    }

    void pop(size_t index)
    {
        if (index > _size) {
            return;
        }
    }

    void pop_front()
    {
        if (empty()) {
            return;
        }

        data[_frontBlock][_frontIndex].~T();
        _frontIndex = (_frontIndex + 1) % 8;
        if (_frontIndex == 0) {
            _frontBlock = (_frontBlock + 1) % _capasity;
        }

        --_size;
    }

    void clear()
    {
        while (!empty()) {
            pop_back();
        }
    }

    DequeIterator<T> begin() { return DequeIterator(this, 0); }

    DequeIterator<T> end() { return DequeIterator(this, _size); }
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
};

#endif // DEQUE_H
