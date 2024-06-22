#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <cstdlib>
#include <memory>
#include <stdexcept>

template<class T>
class BinaryHeap
{
public:
    BinaryHeap() = default;
    BinaryHeap(T *arr, size_t sz)
        : _size(sz)
    {
        reserve(2 * _size);
        std::uninitialized_copy(arr, arr + sz, _data);
        for (size_t iter = 0; iter < _size; ++iter) {
            heapify(iter);
        }
    }

    bool empty()
    {
        return _size == 0;
    }

    void add(T value)
    {
        if (_size + 1 >= _cap) {
            reserve(2 * (_size + 1));
        }

        auto curr = _size++;

        _data[curr] = value;

        while (curr != 0 && _data[(curr - 1) / 2] < _data[curr]) {
            std::swap(_data[(curr - 1) / 2], _data[curr]);
            curr = (curr - 1) / 2;
        }
    }

    const T& top()
    {
        if (_size == 0)
        {
            throw "Heap is empty";
        }

        return _data[0];
    }

    void pop()
    {
        if (_size == 0)
        {
            throw "Heap is empty";
        }

        std::swap(_data[0], _data[--_size]);
        heapify(0);
    }

    void heapify(int curr)
    {
        int left = 2 * curr + 1;
        int right = 2 * curr + 2;
        int greatest = curr;

        if (left < _size && _data[left] > _data[greatest]) {
            greatest = left;
        }

        if (right < _size && _data[right] > _data[greatest]) {
            greatest = right;
        }

        if (greatest != curr) {
            std::swap(_data[curr], _data[greatest]);
            heapify(greatest);
        }
    }

private:
    void reserve(size_t new_cap)
    {
        T *newData = new T[new_cap];

        try {
            std::uninitialized_move(_data, _data + _cap - 1, newData);
        } catch (const std::exception &excep) {
            delete[] newData;
            throw excep;
        }

        delete[] _data;

        _data = newData;
        _cap = new_cap;
    }

    T *_data{new T[1]};
    size_t _cap{1};
    size_t _size{0};
};

#endif // BINARYHEAP_H
