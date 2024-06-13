#ifndef MYSTACK_H
#define MYSTACK_H


#include <QVector>

class MyStack {
private:
    static const int MAX_SIZE = 1000;
    int items[MAX_SIZE];
    int top;
public:
    MyStack();
    bool isEmpty() const;
    bool isFull() const;
    void push(int newItem);
    void clear();
    int pop();
    int peek() const;
    int size() const;
    int peekOrError() const;
    MyStack copy() const;
    QVector<int> toQVector() const;
};

#endif // MYSTACK_H
