#ifndef BINARYHEAPARRAY_H
#define BINARYHEAPARRAY_H

#include <vector>

class BinaryHeapArray {
public:
    BinaryHeapArray();
    void insert(int value);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;

    int size() const { return heap.size(); }
    int at(int index) const { return heap[index]; }
private:
    std::vector<int> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif // BINARYHEAPARRAY_H
