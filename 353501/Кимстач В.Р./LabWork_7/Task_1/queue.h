#ifndef QUEUE_H
#define QUEUE_H

#include <QObject>

class Queue : public QObject
{
    Q_OBJECT

public:
    struct Node {
        int data;
        Node* next;

        Node(int value) : data(value), next(nullptr) {}
    };

    Node* front;
    Node* rear;
    int size;


    Queue();
    ~Queue();

    void enqueue(int value);
    int dequeue();
    int peek();
    bool isEmpty();
    int getSize();
    void clear();
    void makeMinFirst();
    void fillRandomQueue(int size);


    Node* getNodeAt(int index);
};

#endif // QUEUE_H
