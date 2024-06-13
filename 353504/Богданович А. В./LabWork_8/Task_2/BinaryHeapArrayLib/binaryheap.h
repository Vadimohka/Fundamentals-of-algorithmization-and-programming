#ifndef BINARYHEAP_H
#define BINARYHEAP_H

#include <memory>

template <typename T>
class BinaryHeap
{
public:
    BinaryHeap();

    int parent(int i);
    int left(int i);
    int right(int i);

    void heapifyDown(int i);
    void heapifyUp(int i);
    T getMax();

    void decreaseKey(int k, T delta);
    void insert(T value);
    void extractMax();


    void print();
    int getSize();
    T* getArray();

private:
    std::unique_ptr<T[]> array;
    int size;
    int capacity;
};

#endif // BINARYHEAP_H
