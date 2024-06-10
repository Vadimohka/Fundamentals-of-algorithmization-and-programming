#ifndef CUSTOM_STACK_H
#define CUSTOM_STACK_H

#include <QVector>

class CustomStack
{
public:
    CustomStack() = default;

    bool isEmpty() const { return current == -1; }

    bool isFull() const { return current == LIMIT - 1; }

    void push(int value)
    {
        if (isFull()) {
            throw "Stack overflow";
        }
        elements[++current] = value;
    }

    void clear() { current = -1; }

    int pop()
    {
        if (isEmpty()) {
            throw "Stack underflow";
        }
        return elements[current--];
    }

    QVector<int> toVector() const
    {
        QVector<int> vector;
        for (int i = current; i >= 0; --i) {
            vector.append(elements[i]);
        }
        return vector;
    }

    int peek() const
    {
        if (isEmpty()) {
            throw "Stack is empty!";
        }
        return elements[current];
    }

protected:
    static constexpr int LIMIT = 10000;
    int elements[LIMIT];
    int current{-1};
};

#endif // CUSTOM_STACK_H
