#ifndef BINARY_ARRAY_HEAP_H
#define BINARY_ARRAY_HEAP_H

#include <memory>
#include <QException>
#include <QDebug>

class BinaryArrayHeap
{
public:
    BinaryArrayHeap();
    ~BinaryArrayHeap();
    int parent(int i);
    int left(int i);
    int right(int i);
    void heapifyDown(int i);
    void heapifyUp(int i);
    int getMax();
    void decreaseKey(int k, int delta);
    void insert(int value);
    void extractMax();
    void print();
    int getSize();
    int* getArray();

private:
    int arr;
    std::unique_ptr<int[]> array;
    int size;
    int capacity;
};

#endif // BINARY_ARRAY_HEAP_H
