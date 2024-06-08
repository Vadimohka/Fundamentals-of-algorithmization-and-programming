#ifndef STACK_H
#define STACK_H

#include <QVector>
class Stack {
private:
    static const int MAX_SIZE = 1000;
    int items[MAX_SIZE];
    int top;

public:
    Stack();
    bool isEmpty();
    bool isFull();
    void push(int newItem);
    void clear();
    int pop();
    QVector<int> toQVector();
    int peek();
};

#endif // STACK_H
