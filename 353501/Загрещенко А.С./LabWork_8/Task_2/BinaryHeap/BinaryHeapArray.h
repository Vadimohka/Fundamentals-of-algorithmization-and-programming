#ifndef BINARYHEAPARRAY_H
#define BINARYHEAPARRAY_H

#include <QVector>
#include <climits>

class BinaryHeapArray {
private:
    void siftDown(int i);
    void siftUp(int i);

public:
    QVector<int> heap;

    void insert(int key);
    int extractMax();
};

#endif // BINARYHEAPARRAY_H
