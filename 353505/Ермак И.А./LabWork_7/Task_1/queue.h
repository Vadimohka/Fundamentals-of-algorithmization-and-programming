#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;
    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

class Queue {
public:
    Queue();
    ~Queue();

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;

    void splitQueues(Queue& positiveQueue, Queue& negativeQueue) const;

    void printQueue() const;
    Node* getHead() const;

private:
    Node* head;
    Node* tail;
};

#endif // QUEUE_H

