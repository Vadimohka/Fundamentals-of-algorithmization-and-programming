#include "queuenumber.h"
#include "QString"

#ifndef MYQUEUE_H
#define MYQUEUE_H

class MyQueue{
public:
    MyQueue();

    void push(int num);
    int pop();
    int front();
    int back();

    bool isEmpty();
    int size();

    void fnct();

    QString info;
private:    
    QueueNumber* begin;
    QueueNumber* end;
    int count;
};

#endif // MYQUEUE_H
