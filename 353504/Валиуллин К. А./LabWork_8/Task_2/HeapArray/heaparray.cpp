#include "heaparray.h"
#include <stdexcept>

void HeapArray::insert(int value) {
    data.push_back(value);
    heapifyUp(data.size() - 1);
}

int HeapArray::extractMax() {
    if (data.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    int maxValue = data.front();
    data[0] = data.back();
    data.pop_back();
    heapifyDown(0);
    return maxValue;
}

int HeapArray::getMax() const {
    if (data.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return data.front();
}

void HeapArray::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (data[index] <= data[parentIndex]) {
            break;
        }
        std::swap(data[index], data[parentIndex]);
        index = parentIndex;
    }
}

void HeapArray::heapifyDown(int index) {
    int size = data.size();
    while (index < size) {
        int leftChildIndex = 2 * index + 1;
        int rightChildIndex = 2 * index + 2;
        int largest = index;

        if (leftChildIndex < size && data[leftChildIndex] > data[largest]) {
            largest = leftChildIndex;
        }
        if (rightChildIndex < size && data[rightChildIndex] > data[largest]) {
            largest = rightChildIndex;
        }
        if (largest == index) {
            break;
        }
        std::swap(data[index], data[largest]);
        index = largest;
    }
}
