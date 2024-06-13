#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class Queue {
public:
    Queue();
    ~Queue();

    void enqueue(int value);
    int dequeue();
    bool isEmpty() const;
    void clear();
    void bubbleSort();
    Node* getHead() const; // Новый метод для доступа к голове очереди

    void print() const; // for debugging

private:
    Node* head;
    Node* tail;
};

#endif // QUEUE_H
