#ifndef QUEUE_H
#define QUEUE_H

#include <QVector>

template<typename T>
class Queue
{
    struct Element
    {
        Element(const T& value = T(), Element* next = nullptr)
        {
            this->value = value;
            this->next = next;
        }

        T value;
        Element *next = nullptr;
    };

    Element* first = nullptr;
    Element* last = nullptr;

public:
    Queue() = default;

    virtual ~Queue()
    {
        while (first)
        {
            Element * element = first;
            first = first->next;
            delete element;
        }
    }

    bool empty() const
    {
        return !first;
    }

    int size() const
    {
        int n = 0;
        Element* element = first;
        while (element)
        {
            element = element->next;
            ++n;
        }
        return n;
    }

    T& front() const
    {
        if (!first)
        {
            throw "Queue is currently empty!";
        }
        return first->value;
    }

    T& back() const
    {
        if (!first)
        {
            throw "Queue is currently empty!";
        }
        return last->value;
    }

    void push(const T& value)
    {
        Element* element = new Element(value);

        if (first == nullptr)
        {
            first = last = element;
        }
        else
        {
            last = last->next = element;
        }
    }

    void pop()
    {
        if (!first)
        {
            throw "Queue is currently empty!";
        }
        Element* element = first;
        first = first->next;
        delete element;
    }

    void insertAt(const T& value, int pos)
    {
        if (pos < 0 || pos > size())
        {
            throw "Invalid position to insert at!";
            return;
        }
        if (pos == size())
        {
            push(value);
            return;
        }

        Element* element = new Element(value);
        if (pos == 0)
        {
            element->next = first;
            !last ? last = first = element : first = element;
        }
        else
        {
            Element* previous = nullptr;
            Element* current = first;
            for (int i = 0; i < pos; ++i)
            {
                previous = current;
                current = current->next;
            }
            element->next = current;
            previous->next = element;
            if (pos == size())
            {
                last = element;
            }
        }
    }

    void deleteAt(int pos)
    {
        if (pos < 0 || pos > size() - 1)
        {
            throw "Invalid position to delete at!";
            return;
        }
        if (pos == size() - 1)
        {
            pop();
            return;
        }

        if (pos == 0)
        {
            Element* oldFirst = first;
            first = first->next;
            delete oldFirst;
        }
        else
        {
            Element* previous = nullptr;
            Element* current = first;
            for (int i = 0; i < pos; ++i)
            {
                previous = current;
                current = current->next;
            }
            previous->next = current->next;
            delete current;
            if (pos == size() - 1)
            {
                last = previous;
            }
        }
    }

    QVector<T> toVector()
    {
        QVector<T> vec;
        Element *current = first;
        while (current)
        {
            vec.push_back(current->value);
            current = current->next;
        }
        return vec;
    }
};

#endif // QUEUE_H
