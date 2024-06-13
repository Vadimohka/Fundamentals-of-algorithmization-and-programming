#ifndef STACK_H
#define STACK_H

#include <QVector>
#include "Pair.h"

class Stack
{
    QVector<Pair> elements;

public:
    Stack() = default;

    bool isEmpty() const
    {
        return elements.isEmpty();
    }

    int size() const
    {
        return elements.size();
    }

    Pair peek() const
    {
        if (isEmpty())
        {
            throw "Stack is currently empty!";
        }
        return elements.last();
    }

    void push(Pair value)
    {
        elements.push_back(value);
    }

    Pair pop()
    {
        if (isEmpty())
        {
            throw "Stack is currently empty!";
        }
        return elements.takeLast();
    }

    void clear()
    {
        elements.clear();
    }

    QVector<Pair> toVector() const
    {
        return elements;
    }
};

#endif // STACK_H
