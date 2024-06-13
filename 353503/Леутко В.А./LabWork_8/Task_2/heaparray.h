#ifndef HEAPARRAY_H
#define HEAPARRAY_H

#include <vector>
#include <stdexcept>

class HeapArray {
public:
    HeapArray();

    void insert(int key);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;

    std::vector<int> heap;

    void heapifyUp(int index);
    void heapifyDown(int index);

    int parent(int index) const { return (index - 1) / 2; }
    int leftChild(int index) const { return 2 * index + 1; }
    int rightChild(int index) const { return 2 * index + 2; }
};

#endif // HEAPARRAY_H
