#include "heaparray.h"

#include "heaparray.h"
#include <stdexcept>

HeapArray::HeapArray() {}

void HeapArray::insert(int value) {
    data.push_back(value);
    heapifyUp(data.size() - 1);
}

int HeapArray::extractMax() {
    if (data.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    int maxValue = data[0];
    data[0] = data.back();
    data.pop_back();
    heapifyDown(0);
    return maxValue;
}

bool HeapArray::isEmpty() const {
    return data.empty();
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
    while (true) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && data[leftChild] > data[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && data[rightChild] > data[largest]) {
            largest = rightChild;
        }
        if (largest == index) {
            break;
        }
        std::swap(data[index], data[largest]);
        index = largest;
    }
}

size_t HeapArray::size() const {
    return data.size();
}

const int* HeapArray::Data() const {
    return data.data();
}
