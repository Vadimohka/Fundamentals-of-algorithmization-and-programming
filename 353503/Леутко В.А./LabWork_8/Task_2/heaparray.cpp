#include "heaparray.h"

HeapArray::HeapArray() {}

void HeapArray::insert(int key) {
    heap.push_back(key);
    heapifyUp(heap.size() - 1);
}

int HeapArray::extractMax() {
    if (isEmpty()) {
        throw std::out_of_range("Heap is empty");
    }

    int max = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!isEmpty()) {
        heapifyDown(0);
    }
    return max;
}

int HeapArray::getMax() const {
    if (isEmpty()) {
        throw std::out_of_range("Heap is empty");
    }
    return heap[0];
}

bool HeapArray::isEmpty() const {
    return heap.empty();
}

void HeapArray::heapifyUp(int index) {
    while (index > 0 && heap[parent(index)] < heap[index]) {
        std::swap(heap[parent(index)], heap[index]);
        index = parent(index);
    }
}

void HeapArray::heapifyDown(int index) {
    int maxIndex = index;
    int left = leftChild(index);

    if (left < heap.size() && heap[left] > heap[maxIndex]) {
        maxIndex = left;
    }

    int right = rightChild(index);

    if (right < heap.size() && heap[right] > heap[maxIndex]) {
        maxIndex = right;
    }

    if (index != maxIndex) {
        std::swap(heap[index], heap[maxIndex]);
        heapifyDown(maxIndex);
    }
}
