#ifndef ARRAYHEAP_H
#define ARRAYHEAP_H

#include <QVector>
#include <memory>
#include <stdexcept>

template<typename T>
class ArrayHeap
{
public:
    explicit ArrayHeap(size_t capacity)
        : capacity(capacity)
        , heap(std::make_unique<T[]>(capacity))
    {}

    ArrayHeap()
        : heap(std::make_unique<T[]>(capacity))
    {}

    void insert(T value)
    {
        if (size == capacity) {
            resize();
        }
        heap[size] = value;
        heapifyUp(size);
        ++size;
    }

    T extractMin()
    {
        if (size == 0) {
            throw std::underflow_error("Heap is empty");
        }
        int minValue = heap[0];
        heap[0] = heap[size - 1];
        --size;
        heapifyDown(0);
        return minValue;
    }

    bool isEmpty() const { return !size; }

    QVector<T> getHeap()
    {
        QVector<T> arr;
        for (int i = 0; i < size; i++) {
            arr.push_back(heap[i]);
        }
        return arr;
    }

private:
    void heapifyUp(size_t index)
    {
        while (index != 0 && heap[index] < parent(index)) {
            std::swap(heap[index], heap[getParentIndex(index)]);
            index = getParentIndex(index);
        }
    }

    void heapifyDown(size_t index)
    {
        while (hasLeftChild(index)) {
            size_t minChildIndex = getLeftChildIndex(index);
            if (hasRightChild(index) && rightChild(index) < leftChild(index)) {
                minChildIndex = getRightChildIndex(index);
            }
            if (heap[index] < heap[minChildIndex]) {
                break;
            }
            std::swap(heap[index], heap[minChildIndex]);
            index = minChildIndex;
        }
    }

    void resize()
    {
        size_t newCapacity = capacity * 2;
        std::unique_ptr<int[]> newHeap = std::make_unique<int[]>(newCapacity);
        for (size_t i = 0; i < size; ++i) {
            newHeap[i] = heap[i];
        }
        heap = std::move(newHeap);
        capacity = newCapacity;
    }

    size_t getParentIndex(size_t index) const { return (index - 1) / 2; }

    size_t getLeftChildIndex(size_t index) const { return 2 * index + 1; }

    size_t getRightChildIndex(size_t index) const { return 2 * index + 2; }

    bool hasLeftChild(size_t index) const { return getLeftChildIndex(index) < size; }

    bool hasRightChild(size_t index) const { return getRightChildIndex(index) < size; }

    T leftChild(size_t index) const { return heap[getLeftChildIndex(index)]; }

    T rightChild(size_t index) const { return heap[getRightChildIndex(index)]; }

    T parent(size_t index) const { return heap[getParentIndex(index)]; }

    size_t size{0};
    size_t capacity{1};
    std::unique_ptr<int[]> heap;
};

#endif // ARRAYHEAP_H
