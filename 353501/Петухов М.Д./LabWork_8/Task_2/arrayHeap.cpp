#include "arrayHeap.h"

DynamicHeap::DynamicHeap() {
    heap = std::make_unique<long[]>(initialCapacity);
    size = 0;
    maxCapacity = initialCapacity;
}

DynamicHeap::~DynamicHeap() {}

bool DynamicHeap::isEmpty() const {
    return size == 0;
}

void DynamicHeap::insert(long value) {
    if (size >= maxCapacity) {
        resizeHeap();
    }
    heap[size] = value;
    siftUp(size);
    ++size;
}

long DynamicHeap::getMax() const {
    return heap[0];
}

int DynamicHeap::currentSize() const {
    return size;
}

long DynamicHeap::extractMax() {
    if (size == 0) {
        return 0;
    }
    long maxVal = heap[0];
    heap[0] = heap[size - 1];
    --size;
    siftDown(0);
    return maxVal;
}

void DynamicHeap::clearHeap() {
    size = 0;
}

void DynamicHeap::siftDown(int index) {
    int leftChild = index * 2 + 1;
    int rightChild = index * 2 + 2;
    int largest = index;

    if (leftChild < size && heap[leftChild] > heap[largest]) {
        largest = leftChild;
    }
    if (rightChild < size && heap[rightChild] > heap[largest]) {
        largest = rightChild;
    }
    if (largest != index) {
        std::swap(heap[largest], heap[index]);
        siftDown(largest);
    }
}

void DynamicHeap::siftUp(int index) {
    while (index != 0 && heap[getParentIndex(index)] < heap[index]) {
        std::swap(heap[index], heap[getParentIndex(index)]);
        index = getParentIndex(index);
    }
}

int DynamicHeap::getParentIndex(int index) const {
    return (index - 1) / 2;
}

void DynamicHeap::resizeHeap() {
    maxCapacity *= 2;
    std::unique_ptr<long[]> newHeap(new long[maxCapacity]);
    for (int i = 0; i < size; ++i) {
        newHeap[i] = heap[i];
    }
    heap = std::move(newHeap);
}
