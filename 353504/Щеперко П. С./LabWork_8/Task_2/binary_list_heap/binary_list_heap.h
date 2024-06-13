#ifndef BINARY_LIST_HEAP_H
#define BINARY_LIST_HEAP_H

#include <QException>
#include "list.h"

class BinaryListHeap
{
public:
    BinaryListHeap();
    int parent(int i);
    int left(int i);
    int right(int i);
    void heapifyDown(int i);
    void heapifyUp(int i);
    int getMax();
    void decreaseKey(int k, int delta);
    void insert(int value);
    void extractMax();
    QStringList printList();

private:
    List list;
};

#endif // BINARY_LIST_HEAP_H
