#include "stack.h"

template <typename T>
Stack<T>::Stack() : top(nullptr) {}

template <typename T>
Stack<T>::~Stack() {
    while (!isEmpty()) {
        pop();
    }
}

template <typename T>
void Stack<T>::push(T data) {
    StackNode<T>* newNode = new StackNode<T>(data);
    newNode->next = top;
    top = newNode;
}

template <typename T>
T Stack<T>::pop() {
    if (isEmpty()) {
        throw "Stack is empty";
    }
    StackNode<T>* temp = top;
    top = top->next;
    T poppedValue = temp->data;
    delete temp;
    return poppedValue;
}

template <typename T>
T Stack<T>::peek() const {
    if (isEmpty()) {
        throw "Stack is empty";
    }
    return top->data;
}

template <typename T>
bool Stack<T>::isEmpty() const {
    return (top == nullptr);
}
