#ifndef MYHEAPBINARY_H
#define MYHEAPBINARY_H

#include <algorithm>
#include <stdexcept>

template <typename T>
class BinaryHeap {
private:
    size_t _capacity;
    size_t _size{0};
    std::vector<T> data;

    void heapify_down(size_t index) {

        size_t left_child = 2 * index + 1;
        size_t right_child = 2 * index + 2;
        size_t largest = index;

        if (left_child < _size && (data[left_child]) > (data[largest]))
        {
            largest = left_child;
        }

        if (right_child < _size && (data[right_child]) > (data[largest]))
        {
            largest = right_child;
        }

        if (largest != index)
        {
            std::swap(data[index], data[largest]);
            heapify_down(largest);
        }
    }

    void heapify_up(size_t index) {
        if (index == 0) {
            return;
        }

        size_t parent = (index - 1) / 2;
        if ((data[parent]) < (data[index])) {
            std::swap(data[parent], data[index]);
            heapify_up(parent);
        }
    }

public:
    explicit BinaryHeap(size_t capacity)
        : _capacity(capacity), data(std::vector<T>(_capacity)) {}

    ~BinaryHeap() = default;

    void push(T value) {

        data[_size] = value;
        heapify_up(_size);
        _size++;
    }

    void pop() {
        if (_size == 0) {
            throw std::runtime_error("Heap is empty");
        }

        std::swap(data[0], data[_size - 1]);
        _size--;
        heapify_down(0);
    }

    T top() const {
        if (_size == 0) {
            throw std::out_of_range("Heap is empty");
        }

        return data[0];
    }

    size_t size() const {
        return _size;
    }

    bool empty() const {
        return _size == 0;
    }
};


#endif // MYHEAPBINARY_H
