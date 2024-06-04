#include "Deque.h"

#include <stdexcept>

template<typename T>
void Deque<T>::reallocate()
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

template<typename T>
Deque<T>::Deque()
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

template<typename T>
Deque<T>::~Deque()
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

template<typename T>
void Deque<T>::push_back(T value)
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

template<typename T>
void Deque<T>::push_front(T value)
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

template<typename T>
T &Deque<T>::operator[](size_t index)
{
    return data[(_frontBlock + (index + _frontIndex) / BLOCK_SIZE) % _capasity]
               [(index + _frontIndex) % BLOCK_SIZE];
}

template<typename T>
const T &Deque<T>::operator[](size_t index) const
{
    return data[(_frontBlock + (index + _frontIndex) / BLOCK_SIZE) % _capasity]
               [(index + _frontIndex) % BLOCK_SIZE];
}

template<typename T>
const T &Deque<T>::at(size_t index) const
{
    if (index >= _size) {
        throw std::out_of_range("Index out of range");
    }

    return data[(_frontBlock + (index + _frontIndex) / BLOCK_SIZE) % _capasity]
               [(index + _frontIndex) % BLOCK_SIZE];
}

template<typename T>
size_t Deque<T>::size() const
{
    return _size;
}

template<typename T>
bool Deque<T>::empty() const
{
    return _size == 0;
}

template<typename T>
void Deque<T>::pop_back()
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

template<typename T>
void Deque<T>::pop_front()
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

template<typename T>
void Deque<T>::clear()
{
    while (!empty()) {
        pop_back();
    }
}

template<typename T>
DequeIterator<T> Deque<T>::begin()
{
    return DequeIterator(this, 0);
}

template<typename T>
DequeIterator<T> Deque<T>::end()
{
    return DequeIterator(this, _size);
}

template class Deque<int32_t>;
