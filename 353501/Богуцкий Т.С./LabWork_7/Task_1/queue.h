#ifndef QUEUE_H
#define QUEUE_H

#include "QString"
#include <QRandomGenerator>

class Queue
{
public:

    Queue();
    ~Queue();

    void addElement(int value);
    void deleteElement();
    void createQueue(int value);
    void makeRandom();

    QString print();

    int ShowFirst();
    int ShowLast();

    bool IsEmpty();
    bool IsFull();
private:
    int size;
    int *array;
    int front;
    int rear;

};

#endif // QUEUE_H
