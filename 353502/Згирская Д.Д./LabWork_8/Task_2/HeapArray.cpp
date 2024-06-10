#include "HeapArray.h"

void HeapArray::heapifyUp(int index) {
    while (index > 0 && heap[index] > heap[(index - 1) / 2]) {
        std::swap(heap[index], heap[(index - 1) / 2]);
        index = (index - 1) / 2;
    }
}

void HeapArray::heapifyDown(int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int largest = index;

    if (left < _size && heap[left] > heap[largest])
        largest = left;

    if (right < _size && heap[right] > heap[largest])
        largest = right;

    if (largest != index) {
        std::swap(heap[index], heap[largest]);
        heapifyDown(largest);
    }
}

void HeapArray::insert(int value) {
    heap[_size] = value;
    ++_size;
    heapifyUp(_size - 1);
}

int HeapArray::extractMax() {
    if (_size == 0)
        throw std::runtime_error("Heap is empty");

    int maxValue = heap[0];
    heap[0] = heap[_size - 1];
    --_size;

    if (_size != 0) {
        heapifyDown(0);
    }

    return maxValue;
}

int HeapArray::getMax() const {
    if (_size == 0)
        throw std::runtime_error("Heap is empty");

    int maxValue = heap[0];
    for (int i = 0; i < _size; ++i) {
        maxValue = maxValue >= heap[i] ? maxValue : heap[i];
    }
    return maxValue;
}

bool HeapArray::isEmpty() const {
    if (_size == 0)
        return 1;

    return 0;
}

std::vector<int> HeapArray::getHeap() {
    std::vector<int> vector;
    for (int i = 0; i < _size; ++i) {
        vector.push_back(heap[i]);
    }
    return vector;
}

HeapArray::HeapArray() {
    _size = 0;
}

int HeapArray::getSize() {
    return _size;
}
