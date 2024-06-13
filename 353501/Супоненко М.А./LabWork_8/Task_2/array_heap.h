#ifndef ARRAY_HEAP_H
#define ARRAY_HEAP_H

#include <vector>
#include <stdexcept>

class ArrayHeap {
public:
    ArrayHeap();
    void insert(int value);
    int extractMax();
    int getMax() const;
    bool isEmpty() const;

private:
    std::vector<int> heap;
    int size;

    void siftUp(int index);
    void siftDown(int index);
};

#endif // ARRAY_HEAP_H
