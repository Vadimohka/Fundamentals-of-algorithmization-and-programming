#ifndef STACK_H
#define STACK_H

#include <QList>
#include <QDebug>


class Stack
{
private:
    static const int max_size = 1000;

    int list[max_size];

    int top;

public:
    Stack();

    bool isEmpty();
    bool isFull();
    void push(int number);
    int pop();
    int size();

    void clear();

    QList<int>* Stack_to_list();

};

#endif // STACK_H
