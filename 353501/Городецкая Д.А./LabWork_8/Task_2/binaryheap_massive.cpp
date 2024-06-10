#include "binaryheap_massive.h"
#include <stdexcept>

template<typename T>
binaryheap_massive<T>::binaryheap_massive()
    : _data(new T[INIT_CAPACITY])
    , _size(0)
    , _capacity(INIT_CAPACITY)
{}

template<typename T>
binaryheap_massive<T>::~binaryheap_massive()
{
    clear();
}

template<typename T>
void binaryheap_massive<T>::clear()
{
    _size = 0;
}

template<typename T>
void binaryheap_massive<T>::push(T value)
{
    if (is_full()) {
        grow();
    }
    _data[_size++] = value;
    for (int64_t i = (_size / 2) - 1; i >= 0; i--) {
        heapify(i);
    }
}

template<typename T>
T binaryheap_massive<T>::pop()
{
    if (empty()) {
        throw std::runtime_error("Heap is empty");
    }

    T max_value = _data[0];
    _data[0] = _data[--_size];
    heapify(0);
    return max_value;
}

template<typename T>
T &binaryheap_massive<T>::max()
{
    if (empty()) {
        throw std::runtime_error("Heap is empty");
    }

    return _data[0];
}

template<typename T>
size_t binaryheap_massive<T>::size()
{
    return _size;
}

template<typename T>
bool binaryheap_massive<T>::empty()
{
    return _size == 0;
}

template<typename T>
size_t binaryheap_massive<T>::heapify(size_t index)
{
    size_t largest = index;
    size_t left = 2 * index + 1;
    size_t right = 2 * index + 2;

    if (left < _size && _data[left] > _data[largest]) {
        largest = left;
    }

    if (right < _size && _data[right] > _data[largest]) {
        largest = right;
    }

    if (largest != index) {
        std::swap(_data[index], _data[largest]);
        heapify(largest);
    }

    return largest;
}

template<typename T>
void binaryheap_massive<T>::grow()
{
    _capacity *= 2;

    std::unique_ptr<T[]> new_data(new T[_capacity]);
    std::copy(_data.get(), _data.get() + _size, new_data.get());
    _data.swap(new_data);
}

template<typename T>
bool binaryheap_massive<T>::is_full()
{
    return _size == _capacity;
}
template class binaryheap_massive<int32_t>;
