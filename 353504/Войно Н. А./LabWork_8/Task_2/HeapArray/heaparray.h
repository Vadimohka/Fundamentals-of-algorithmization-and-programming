#ifndef HEAPARRAY_H
#define HEAPARRAY_H

#pragma once
#include <vector>

class HeapArray {
public:
    HeapArray() = default;

    void insert(int value);
    int extractMax();
    int getMax() const;

    bool isEmpty() const { return data.empty(); }

private:
    std::vector<int> data;

    void heapifyUp(int index);
    void heapifyDown(int index);
};


#endif // HEAPARRAY_H
