#ifndef L8_T2_HEAPARRAY_H
#define L8_T2_HEAPARRAY_H


#include <vector>
#include <memory>
#include <algorithm>
#include <iostream>

class HeapArray {
private:
    int heap[100];
    int _size;

    void heapifyUp(int index);
    void heapifyDown(int index);

public:
    HeapArray();
    void insert(int value);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;
    std::vector<int> getHeap();
    int getSize();
};


#endif //L8_T2_HEAPARRAY_H
