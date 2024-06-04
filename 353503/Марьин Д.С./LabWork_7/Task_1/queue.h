#ifndef QUEUE_H
#define QUEUE_H

#include "QtCore/qstring.h"

template <typename T>
struct Node
{
    T data;
    Node* next;
    Node* prev;
    Node(T data)
    {
        this->data = data;
        this->next = nullptr;
        this->prev = nullptr;
    }
};

template <typename T>
class Queue
{
public:
    Queue();
    ~Queue();
    void push_back(T data);
    T pop_back();
    void push_front(T data);
    T pop_front();
    T front();
    T back();
    bool empty();
    int size();
    void clear();
    // extended methods
    void bubbleSort();
    QString print();
private:
    Node<T>* head;
    Node<T>* tail;
    size_t count;
};
template <typename T>
Queue<T>::Queue()
{
    head = nullptr;
    tail = nullptr;
    count = 0;
}
template <typename T>
Queue<T>::~Queue()
{
    clear();
}
template <typename T>
void Queue<T>::push_back(T data)
{
    Node<T>* temp = new Node<T>(data);
    temp->prev = tail;
    temp->next = nullptr;
    if (tail != nullptr)
    {
        tail->next = temp;
    }
    tail = temp;
    if (head == nullptr)
    {
        head = temp;
    }
    count++;
}

template <typename T>
T Queue<T>::pop_back()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    Node<T>* temp = tail;
    T data = tail->data;
    tail = tail->prev;
    if (tail != nullptr)
    {
        tail->next = nullptr;
    }
    delete temp;
    count--;
    return data;
}

template <typename T>
void Queue<T>::push_front(T data)
{
    Node<T>* temp = new Node<T>(data);
    temp->prev = nullptr;
    temp->next = head;
    if (head != nullptr)
    {
        head->prev = temp;
    }
    head = temp;
    if (tail == nullptr)
    {
        tail = temp;
    }
    count++;
}

template <typename T>
T Queue<T>::pop_front()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    Node<T>* temp = head;
    T data = head->data;
    head = head->next;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    delete temp;
    count--;
    return data;
}

template <typename T>
T Queue<T>::front()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    return head->data;
}

template <typename T>
T Queue<T>::back()
{
    if (empty())
    {
        throw std::out_of_range("Queue is empty");
    }
    return tail->data;
}

template <typename T>
bool Queue<T>::empty()
{
    return count == 0;
}

template <typename T>
int Queue<T>::size()
{
    return count;
}

template <typename T>
void Queue<T>::clear()
{
    while (!empty())
    {
        pop_front();
    }
}

template <typename T>
void Queue<T>::bubbleSort()
{
    Node<T>* temp = head;
    for (size_t i = 0; i < count; i++)
    {
        Node<T>* temp2 = head;
        for (size_t j = 0; j < count - i - 1; j++)
        {
            if (temp2 ->next != nullptr && temp2->data > temp2->next->data)
            {
                T data = temp2->data;
                temp2->data = temp2->next->data;
                temp2->next->data = data;
            }
            temp2 = temp2->next;
        }
    }
}

template <typename T>
QString Queue<T>::print()
{
    QString val;
    Node<T>* temp = head;
    while (temp != nullptr)
    {
        val += QString::number(temp->data) + " ";
        temp = temp->next;
    }
    val += "\n";
    return val;
}

#endif // QUEUE_H
