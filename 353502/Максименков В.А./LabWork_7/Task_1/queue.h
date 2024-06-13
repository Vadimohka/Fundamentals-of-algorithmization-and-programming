#ifndef QUEUE_H
#define QUEUE_H
#include <QString>
#include "node.h"

class Queue // двухсторонняя очередь
{
private:
    int sz;
    Node* head;
    Node* tail;

public:
    Queue();
    ~Queue();

    bool isEmpty() const;
    int size() const;
    void addInEnd(int data);
    void addInBegin(int data);
    void delFromBegin();
    void delFromEnd();
    int peekInBegin();
    int peekInEnd();
    void clear();
    QString toString();
};

#endif // QUEUE_H
