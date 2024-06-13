#ifndef STACK_H
#define STACK_H

#include <QVector>

template<typename T>
class Stack
{
private:
    struct Node
    {
        T value;
        Node* prev = nullptr;

        Node(const T& val = T()) : value(val) {}
    };

    Node* topNode = nullptr;
    long long size_ = 0;

public:
    Stack() {}

    ~Stack()
    {
        clear();
    }

    void clear()
    {
        while (!empty())
            pop();
    }

    void push(const T& value)
    {
        Node* newNode = new Node(value);
        newNode->prev = topNode;
        topNode = newNode;
        size_++;
    }

    void pop()
    {
        if (topNode == nullptr)
            throw "No elements in stack";

        Node* temp = topNode;
        topNode = topNode->prev;
        delete temp;
        size_--;
    }

    T& top()
    {
        return topNode->value;
    }

    long long size()
    {
        return size_;
    }

    bool empty()
    {
        return size_ == 0;
    }

    QVector<T> toQVector()
    {
        QVector<T> result;
        Node* current = topNode;
        while (current)
        {
            result.push_front(current->value);
            current = current->prev;
        }
        return result;
    }
};

#endif // STACK_H
