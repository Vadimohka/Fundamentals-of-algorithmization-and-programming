#include "stack.h"

/*Stack::Stack() {}
#include <QString>

template<typename T>
Stack<T>::Stack()
    : top(nullptr)
{}

template<typename T>
Stack<T>::Stack(const Stack<T> &other)
    : top(nullptr)
{
    if (other.top == nullptr) {
        return;
    }

    top = new Node(other.top->key, other.top->value);
    Node *current = top;
    Node *otherCurrent = other.top->next;
    while (otherCurrent) {
        current->next = new Node(otherCurrent->key, otherCurrent->value);
        current = current->next;
        otherCurrent = otherCurrent->next;
    }
}

template<typename T>
Stack<T>::~Stack()
{
    clear();
}

template<typename T>
void Stack<T>::push(int64_t key, T value)
{
    Node *newTop = new Node(key, value);
    newTop->next = top;
    top = newTop;
}

template<typename T>
void Stack<T>::pop(int64_t &key, T &value)
{
    while (top == nullptr) {
        return;
    }

    Node *temp = top;
    key = top->key;
    value = top->value;
    top = top->next;
    delete temp;
}

template<typename T>
void Stack<T>::pop()
{
    while (top == nullptr) {
        return;
    }

    Node *temp = top;
    top = top->next;
    delete temp;
}

template<typename T>
void Stack<T>::clear()
{
    while (top) {
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

template<typename T>
bool Stack<T>::empty()
{
    return top == nullptr;
}

template class Stack<QString>;*/
