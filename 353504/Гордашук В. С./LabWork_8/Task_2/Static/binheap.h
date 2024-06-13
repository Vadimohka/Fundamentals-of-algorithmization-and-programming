#ifndef BINHEAP_H
#define BINHEAP_H

#include <QVector>
#include <QDebug>
#include <QException>

class BinaryHeap
{
public:
    BinaryHeap();
private:
    QVector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void shiftUp(int i);

    void shiftDown(int i);

public:
    void insert(int p);
    int extractMax();
    void remove(int i);
    QString print();
};

#endif // BINHEAP_H
