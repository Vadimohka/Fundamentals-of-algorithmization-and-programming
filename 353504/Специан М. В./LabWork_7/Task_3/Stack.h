#ifndef STACK_H
#define STACK_H

#include <QVector>

class Stack
{
    struct Element
    {
        Element(int value, Element* previous = nullptr)
        {
            this->value = value;
            this->previous = previous;
        }

        int value;
        Element *previous = nullptr;
    };

    Element* top = nullptr;

public:
    Stack() = default;

    virtual ~Stack()
    {
        clear();
    }

    bool isEmpty() const
    {
        return !top;
    }

    int size() const
    {
        int n = 0;
        Element* element = top;
        while (element)
        {
            element = element->previous;
            ++n;
        }
        return n;
    }

    int peek() const
    {
        if (!top)
        {
            throw "Stack is currently empty!";
        }
        return top->value;
    }

    void push(int value)
    {
        Element* element = new Element(value);

        if (!top)
        {
            top = element;
        }
        else
        {
            element->previous = top;
            top = element;
        }
    }

    int pop()
    {
        if (!top)
        {
            throw "Stack is currently empty!";
        }
        Element* element = top;
        int value = element->value;
        top = top->previous;
        delete element;
        return value;
    }

    void clear()
    {
        while (top)
        {
            Element* element = top;
            top = top->previous;
            delete element;
        }
    }

    QVector<int> toVector()
    {
        QVector<int> vec;
        Element* element = top;
        while (element)
        {
            vec.push_back(element->value);
            element = element->previous;
        }
        return vec;
    }
};

#endif // STACK_H
