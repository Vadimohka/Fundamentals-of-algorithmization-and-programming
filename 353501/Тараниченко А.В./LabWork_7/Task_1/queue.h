#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"
#include "node.cpp"
#include <QListWidget>
#include <cstddef>

template <typename T>
class Queue
{
public:
    Queue();
    ~Queue();
    bool empty();
    size_t size();

    T &front();
    T &back();

    void push(T element);
    void pop();

    //individual

    void clear();
    void insertAfterMax(Queue<T> &q2);

    void print(QListWidget* view);
private:
    Node<T>* head;
    size_t _size;

};




#endif // QUEUE_H

