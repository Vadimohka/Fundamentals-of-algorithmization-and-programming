#include "array_heap.h"

ArrayHeap::ArrayHeap() : size(0) {}

void ArrayHeap::insert(int value) {
    if (size >= heap.size()) {
        heap.push_back(value);
    } else {
        heap[size] = value;
    }
    siftUp(size);
    ++size;
}

int ArrayHeap::extractMax() {
    if (isEmpty()) throw std::runtime_error("Heap is empty");
    int result = heap[0];
    heap[0] = heap[--size];
    siftDown(0);
    return result;
}

int ArrayHeap::getMax() const {
    if (isEmpty()) throw std::runtime_error("Heap is empty");
    return heap[0];
}

bool ArrayHeap::isEmpty() const {
    return size == 0;
}

void ArrayHeap::siftUp(int index) {
    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[index] <= heap[parent]) break;
        std::swap(heap[index], heap[parent]);
        index = parent;
    }
}

void ArrayHeap::siftDown(int index) {
    while (2 * index + 1 < size) {
        int leftChild = 2 * index + 1;
        int rightChild = 2 * index + 2;
        int maxIndex = leftChild;

        if (rightChild < size && heap[rightChild] > heap[leftChild]) {
            maxIndex = rightChild;
        }

        if (heap[index] >= heap[maxIndex]) break;
        std::swap(heap[index], heap[maxIndex]);
        index = maxIndex;
    }
}
