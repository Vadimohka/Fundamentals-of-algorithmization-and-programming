#ifndef DOUBLYLINKEDQUEUE_H
#define DOUBLYLINKEDQUEUE_H

#include "node.h"

class DoublyLinkedQueue {
private:
    Node* head;
    Node* tail;
    int totalNodes;

public:
    Node* current;
    DoublyLinkedQueue();

    void push_back(int value);

    void push_front(int value);

    int pop_back();

    int pop_front();

    void convertToRing();

    void moveForward();

    void moveBackward();

    int getCurrentValue() const;

    Node* getHead() const;

    int getTotalNodes() const;

    ~DoublyLinkedQueue();
};
#endif // DOUBLYLINKEDQUEUE_H
