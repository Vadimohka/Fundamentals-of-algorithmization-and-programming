#include "binaryheaparray.h"

#include <stdexcept>

BinaryHeapArray::BinaryHeapArray() {}

void BinaryHeapArray::insert(int value) {
    heap.push_back(value);
    heapifyUp(heap.size() - 1);
}

int BinaryHeapArray::extractMax() {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    int maxValue = heap.front();
    heap.front() = heap.back();
    heap.pop_back();
    heapifyDown(0);
    return maxValue;
}

int BinaryHeapArray::getMax() const {
    if (heap.empty()) {
        throw std::runtime_error("Heap is empty");
    }
    return heap.front();
}

bool BinaryHeapArray::isEmpty() const {
    return heap.empty();
}

void BinaryHeapArray::heapifyUp(int index) {
    while (index > 0) {
        int parentIndex = (index - 1) / 2;
        if (heap[index] <= heap[parentIndex]) {
            break;
        }
        std::swap(heap[index], heap[parentIndex]);
        index = parentIndex;
    }
}

void BinaryHeapArray::heapifyDown(int index) {
    int size = heap.size();
    while (index < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int largest = index;

        if (leftChild < size && heap[leftChild] > heap[largest]) {
            largest = leftChild;
        }
        if (rightChild < size && heap[rightChild] > heap[largest]) {
            largest = rightChild;
        }
        if (largest == index) {
            break;
        }
        std::swap(heap[index], heap[largest]);
        index = largest;
    }
}
