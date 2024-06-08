#ifndef STACK_H
#define STACK_H

#include "stacknode.h"
#include "stacknode.cpp"

template <typename T>
class Stack {
private:
    StackNode<T>* top;

public:
    Stack();
    ~Stack();

    void push(T data);
    T pop();
    T peek() const;
    bool isEmpty() const;
};

#endif // STACK_H
