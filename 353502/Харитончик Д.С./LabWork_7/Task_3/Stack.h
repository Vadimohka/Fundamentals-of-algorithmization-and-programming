#ifndef STACK_H
#define STACK_H
#pragma once
#include <QVector>
class Stack {
private:
    static const int MAX_SIZE = 10000;
    int items[MAX_SIZE];
    int top;

public:
    Stack(): top(-1) {}
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    void push(int newItem) {
        if (isFull()) {
            throw "Stack overflow";
        }
        top++;
        items[top] = newItem;
    }
    void clear(){
        top = -1;
    }
    int pop() {
        if (isEmpty()) {
            throw "Stack underflow";
        }
        int removedItem = items[top];
        top--;
        return removedItem;
    }
    QVector<int> toQVector(){
        QVector<int> vec;
        for (int i = top; i >= 0; --i) {
            vec.append(items[i]);
        }
        return vec;
    }
    int peek() {
        if (!isEmpty()) {
            return items[top];
        }
        throw "Stack is empty!";
    }
};

#endif // STACK_H
