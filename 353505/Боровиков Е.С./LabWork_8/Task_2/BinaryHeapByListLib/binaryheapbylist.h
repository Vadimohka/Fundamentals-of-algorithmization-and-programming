#ifndef BINARYHEAPBYLIST_H
#define BINARYHEAPBYLIST_H
#include "list.h"
#include "list.cpp"

template <typename T>
class BinaryHeapByList
{
public:
    BinaryHeapByList();

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

private:
    List<T> list;
};

#endif // BINARYHEAPBYLIST_H
