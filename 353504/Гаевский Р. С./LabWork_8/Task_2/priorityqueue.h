#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include <QVector>
#include <memory>

template<typename T>
class PriorityQueue {
private:
    std::unique_ptr<T[]> heap;
    int len;
    int capacity;

    void grow();

    void heapifyUp(int cur);

    void heapifyDown(int cur);

public:
    PriorityQueue();

    ~PriorityQueue();

    void push(T x);

    T pop();

    bool empty();

    void clear();

    T getMax();

    T getMin();

    QVector<T> toVec();
};

#endif // PRIORITYQUEUE_H
