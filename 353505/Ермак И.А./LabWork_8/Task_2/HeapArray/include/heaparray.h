#ifndef HEAPARRAY_H
#define HEAPARRAY_H

#include <vector>

class HeapArray {
public:
    HeapArray();
    size_t size() const;
    const int* Data() const;
    void insert(int value);
    int extractMax();
    bool isEmpty() const;

private:
    std::vector<int> data;

    void heapifyUp(int index);
    void heapifyDown(int index);
};

#endif // HEAPARRAY_H
