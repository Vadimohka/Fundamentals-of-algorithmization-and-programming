#ifndef MYDEQUE_H
#define MYDEQUE_H

#include <cstddef>
#include <cstdint>
#include <iterator>

constexpr size_t BLOCK_SIZE = 8;
constexpr size_t INITAL_CAPASITY = 2;
constexpr int64_t NOTHING = -1;

template<typename T>
class DequeIterator;

template<typename T>
class MyDeque
{
private:
    T **data;
    size_t _size;
    size_t _capasity;
    int64_t _frontBlock;
    int64_t _frontIndex;
    int64_t _backBlock;
    int64_t _backIndex;

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
            newData[i] = reinterpret_cast<T *>(new int8_t[sizeof(T) * BLOCK_SIZE]);
        }

        delete[] reinterpret_cast<int8_t *>(data);
        data = newData;
        _capasity = newCap;
        _frontBlock = 0;
        _backBlock = (_size - 1) / BLOCK_SIZE;
    }

public:
    using iterator = DequeIterator<T>;

    MyDeque()
        : _size(0)
        , _capasity(INITAL_CAPASITY)
        , _frontBlock(NOTHING)
        , _frontIndex(NOTHING)
        , _backBlock(NOTHING)
        , _backIndex(NOTHING)
    {
        data = reinterpret_cast<T **>(new char *[_capasity * sizeof(T *)]);

        for (size_t i = 0; i < _capasity; ++i) {
            data[i] = reinterpret_cast<T *>(new char[BLOCK_SIZE * sizeof(T)]);
        }
    }
    ~MyDeque()
    {
        for (size_t i = 0; i < _size; ++i) {
            data[(_frontBlock + (i + _frontIndex) / BLOCK_SIZE) % _capasity]
                [(i + _frontIndex) % BLOCK_SIZE]
                    .~T();
        }

        for (size_t i = 0; i < _capasity; ++i) {
            delete[] reinterpret_cast<int8_t *>(data[i]);
        }

        delete[] reinterpret_cast<int8_t *>(data);
    }

    void push_back(T value)
    {
        if ((_size == _capasity * BLOCK_SIZE)
            || (((static_cast<int64_t>((_backBlock + 1) % _capasity)) == _frontBlock)
                && _backIndex == BLOCK_SIZE - 1)) {
            reallocate();
        }

        if (_frontBlock == NOTHING) {
            _frontBlock = 0;
            _frontIndex = 0;
            _backBlock = 0;
            _backIndex = 0;
        } else {
            _backIndex = (_backIndex + 1) % BLOCK_SIZE;
            if (_backIndex == 0) {
                _backBlock = (_backBlock + 1) % _capasity;
            }
        }

        new (&data[_backBlock][_backIndex]) T(std::move(value));
        ++_size;
    }

    void push_front(T value)
    {
        if (_size == _capasity * BLOCK_SIZE
            || (((static_cast<int64_t>((_frontBlock - 1 + _capasity) % _capasity)) == _backBlock)
                && _frontIndex == 0)) {
            reallocate();
        }

        if (_frontBlock == NOTHING) {
            _frontBlock = 0;
            _frontIndex = 0;
            _backBlock = 0;
            _backIndex = 0;
        } else {
            _frontIndex = (_frontIndex - 1 + BLOCK_SIZE) % BLOCK_SIZE;
            if (_frontIndex == BLOCK_SIZE - 1) {
                _frontBlock = (_frontBlock - 1 + _capasity) % _capasity;
            }
        }

        new (&data[_frontBlock][_frontIndex]) T(std::move(value));
        ++_size;
    }

    const T &operator[](size_t index) const
    {
        index = index % _size;

        return data[(_frontBlock + (index + _frontIndex) / BLOCK_SIZE) % _capasity]
                   [(index + _frontIndex) % BLOCK_SIZE];
    }

    T &operator[](size_t index)
    {
        index = index % _size;

        return data[(_frontBlock + (index + _frontIndex) / BLOCK_SIZE) % _capasity]
                   [(index + _frontIndex) % BLOCK_SIZE];
    }
    const T &at(size_t index) const
    {
        index = index % _size;

        return data[(_frontBlock + (index + _frontIndex) / BLOCK_SIZE) % _capasity]
                   [(index + _frontIndex) % BLOCK_SIZE];
    }

    size_t size() const
    {
        return _size;
    }
    bool empty() const
    {
        return _size == 0;
    }

    void pop_back()
    {
        if (empty()) {
            return;
        }

        data[_backBlock][_backIndex].~T();
        _backIndex = (_backIndex - 1 + BLOCK_SIZE) % BLOCK_SIZE;
        if (_backIndex == BLOCK_SIZE - 1) {
            _backBlock = (_backBlock - 1 + _capasity) % _capasity;
        }

        --_size;
    }
    void pop_front()
    {
        if (empty()) {
            return;
        }

        data[_frontBlock][_frontIndex].~T();
        _frontIndex = (_frontIndex + 1) % BLOCK_SIZE;
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

    DequeIterator<T>begin()
    {
        return DequeIterator(this, 0);
    }


    DequeIterator<T> end()
    {
        return DequeIterator(this, _size);
    }
};

template<typename T>
class DequeIterator
{
private:
    MyDeque<T> *deque;
    size_t index;

public:
    using difference_type = std::ptrdiff_t;
    using value_type = T;
    using pointer = T *;
    using reference = T &;
    using iterator_category = std::random_access_iterator_tag;

    DequeIterator(MyDeque<T> *deque, size_t index)
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

#endif // MYDEQUE_H
