#ifndef ARRAYHEAP_H
#define ARRAYHEAP_H

#include <QVector>
#include <memory>

class ArrayHeap
{
private:
    std::unique_ptr<long[]> heap;
    int len = 0;
    int capacity = 0;

    void grow();

    void heapifyUp(int cur);

    void heapifyDown(int cur);

public:
    ArrayHeap();

    ~ArrayHeap();

    void push(long x);;

    long pop();;

    bool empty();

    void clear();

    QVector<long> toVec();

};


#endif // ARRAYHEAP_H
