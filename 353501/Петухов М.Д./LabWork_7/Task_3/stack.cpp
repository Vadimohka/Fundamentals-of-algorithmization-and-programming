#include "stack.h"

void Stack::push(QPair<int, int> pair){
    if (top >= (MAX - 1)) {
        throw "Stack overflow";
    }
    else {
        a[++top] = pair;
    }
}

QPair<int, int> Stack::pop() {
    if (isEmpty()) {
        throw "Stack underflow";
    }
    QPair<int, int> removedItem = a[--top];
    return removedItem;
}

QPair<int, int> Stack::peek()
{
    if (isEmpty()) {
        throw "Stack underflow";
    }
    else {
        QPair<int, int> x = a[top];
        return x;
    }
}

bool Stack::isEmpty(){
    return (top < 0);
}

bool Stack::isFull(){
    return top == MAX - 1;
}

void Stack::clearStack() {
    top = -1;
}

QVector<QPair<int, int>> Stack::toQVector() {
    QVector<QPair<int, int>> vec;
    for (int i = top; i >= 0; --i) {
        vec.append(a[i]);
    }
    return vec;
}