#include "mystack.h"

MyStack::MyStack() : top(-1) {}

bool MyStack::isEmpty() const {
    return top == -1;
}

bool MyStack::isFull() const {
    return top == MAX_SIZE - 1;
}

void MyStack::push(int newItem) {
    if (isFull()) {
        throw "Stack overflow";
    }
    ++top;
    items[top] = newItem;
}

int MyStack::pop() {
    if (isEmpty()) {
        throw "Stack underflow";
    }
    int removedItem = items[top];
    --top;
    return removedItem;
}

int MyStack::peek() const {
    if (!isEmpty()) {
        return items[top];
    }
    throw "Stack underflow";
}

int MyStack::size() const {
    return top + 1;
}

int MyStack::peekOrError() const {
    if (!isEmpty()) {
        return items[top];
    }
    throw "Stack underflow";
}

MyStack MyStack::copy() const {
    MyStack newStack;
    for (int i = 0; i <= top; ++i) {
        newStack.push(items[i]);
    }
    return newStack;
}

QVector<int> MyStack::toQVector() const
{
    QVector<int> vec;
    for (int i = top; i >= 0; --i) {
        vec.append(items[i]);
    }
    return vec;
}

void MyStack::clear() {
    top = -1;
}
