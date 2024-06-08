#ifndef MY_STACK_H
#define MY_STACK_H

#include <QVector>

class my_stack
{
private:
    static const int max_size = 1000;
    int items[max_size];
    int top;
public:
    my_stack();
    bool isEmpty() const;
    bool isFull() const;
    int size() const;
    void clear();
    void push(int new_item);
    int pop();
    int peek() const;
    QVector<int> toQVector();
};

#endif // MY_STACK_H
