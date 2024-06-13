#ifndef STACK_H
#define STACK_H
#pragma once
#include <QVector>
class Stack {
private:
    static const int MAX_SIZE = 10000;

    int top;
    struct Item
    {
        int key;
        int value;
        Item()
            : key(0)
            , value(0)
        {}
        Item(int key, int value)
            : key(key)
            , value(value)
        {}
    };
    Item a[MAX_SIZE];

public:
    Stack(): top(-1) {}
    bool isEmpty() {
        return top == -1;
    }
    bool isFull() {
        return top == MAX_SIZE - 1;
    }
    void push(int key, int newItem)
    {
        if (isFull()) {
            throw "Error! Stack overflow!";
        }
        top++;
        a[top].key = key;
        a[top].value = newItem;
    }
    void clear(){
        top = -1;
    }
    int pop() {
        if (isEmpty()) {
            throw "Error! Stack underflow!";
        }
        //int removedItem = items[top];
        Item removedItem = a[top];
        top--;
        return removedItem.value;
    }
    QVector<int> toQVectorValue()
    {
        QVector<int> vec;
        for (int i = top; i >= 0; --i) {
            vec.append(a[i].value);
        }
        return vec;
    }
    QVector<int> toQVectorKey()
    {
        QVector<int> vec;
        for (int i = top; i >= 0; --i) {
            vec.append(a[i].key);
        }
        return vec;
    }
    int peek() {
        if (!isEmpty()) {
            return a[top].value;
        }
        throw "Error! Stack is empty!";
    }
};

#endif // STACK_H
