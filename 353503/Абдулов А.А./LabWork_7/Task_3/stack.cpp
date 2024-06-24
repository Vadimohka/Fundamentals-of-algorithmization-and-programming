#include "stack.h"

Stack::Stack() : top(-1) {}

bool Stack::isEmpty() {
    return top == -1;
}

bool Stack::isFull()  {
    return top == MAX_SIZE - 1;
}

void Stack::push(int key, int value) {
    if (isFull()) {
        throw "Stack overflow";
    }
    ++top;
    items[top] = Item(key, value);
}

Stack::Item Stack::pop() {
    if (isEmpty()) {
        throw "Stack underflow";
    }
    Item removedItem = items[top];
    --top;
    return removedItem;
}

QVector<int> Stack::toQVectorValue(){
    QVector<int> vec;
    for (int i = top; i >= 0; --i) {
        vec.append(items[i].value);
    }
    return vec;
}

QVector<int> Stack::toQVectorKey(){
    QVector<int> vec;
    for (int i = top; i >= 0; --i) {
        vec.append(items[i].key);
    }
    return vec;
}

Stack::Item Stack::peek() {
    if (!isEmpty()) {
        return items[top];
    }
    throw "Stack underflow";
}

void Stack::clear() {
    top = -1;
}


