#ifndef HEAPARRAY_H
#define HEAPARRAY_H

#include <iostream>
#include <vector>
#include <memory>

template <typename T>
class HeapArray {
public:
    void push(const T& value) {
        heap.push_back(value);
        siftUp(heap.size() - 1);
    }

    void pop() {
        std::swap(heap[0], heap[heap.size() - 1]);
        heap.pop_back();
        siftDown(0);
    }

    const T& top() const {
        return heap[0];
    }

    bool empty() const {
        return heap.empty();
    }
    void heapify(const T arr[], size_t n) {
        heap.clear();
        heap.reserve(n);
        for (size_t i = 0; i < n; ++i) {
            heap.push_back(arr[i]);
        }

        for (int i = n / 2 - 1; i >= 0; --i) {
            siftDown(i);
        }
    }

    int size() const {
        return heap.size();
    }

    void clear() {
        heap.clear();
    }

    T& operator[](size_t index) {
        return heap[index];
    }

    const T& operator[](size_t index) const {
        return heap[index];
    }


private:
    std::vector<T> heap;

    size_t parent(size_t i) {
        return (i - 1) / 2;
    }

    size_t left(size_t i) {
        return 2 * i + 1;
    }

    size_t right(size_t i) {
        return 2 * i + 2;
    }

    void siftUp(size_t i) {
        while (i > 0 && heap[parent(i)] < heap[i]) {
            std::swap(heap[i], heap[parent(i)]);
            i = parent(i);
        }
    }

    void siftDown(size_t i) {
        size_t largest = i;
        size_t l = left(i);
        size_t r = right(i);

        if (l < heap.size() && heap[l] > heap[largest])
            largest = l;
        if (r < heap.size() && heap[r] > heap[largest])
            largest = r;

        if (largest != i) {
            std::swap(heap[i], heap[largest]);
            siftDown(largest);
        }
    }
};

#endif // HEAPARRAY_H
