#ifndef QUEUE_H
#define QUEUE_H

#include <QString>

template <typename T>
struct Node
{
    T data;
    Node* next{nullptr};
    Node* prev{nullptr};
    Node(T data) : data(data) {}
};

template <typename T>
class Queue
{
public:
    Queue();
    ~Queue();

    void push_back(T data);
    void push_front(T data);
    void pop_back();
    void pop_front();
    T front();
    T back();
    void clear();
    bool empty();
    QString print();

private:
    Node<T>* head{nullptr};
    Node<T>* tail{nullptr};
};

template <typename T>
Queue<T>::Queue()
{
}

template <typename T>
Queue<T>::~Queue()
{
    while (!empty())
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void Queue<T>::push_back(T data)
{
    Node<T>* newNode = new Node<T>(data);

    if (empty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
void Queue<T>::push_front(T data)
{
    Node<T>* newNode = new Node<T>(data);

    if (empty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

template <typename T>
void Queue<T>::pop_back()
{
    if (empty())
    {
        return;
    }

    Node<T>* temp = tail;
    tail = tail->prev;
    delete temp;

    if (tail == nullptr)
    {
        head = nullptr;
    }
    else
    {
        tail->next = nullptr;
    }
}

template <typename T>
void Queue<T>::pop_front()
{
    if (empty())
    {
        return;
    }

    Node<T>* temp = head;
    head = head->next;
    delete temp;

    if (head == nullptr)
    {
        tail = nullptr;
    }
    else
    {
        head->prev = nullptr;
    }
}

template <typename T>
T Queue<T>::front()
{
    if (empty())
    {
        return -1;
    }

    return head->data;
}

template <typename T>
T Queue<T>::back()
{
    if (empty())
    {
        return -1;
    }

    return tail->data;
}

template <typename T>
void Queue<T>::clear()
{
    while (!empty())
    {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
    tail = nullptr;
}

template <typename T>
bool Queue<T>::empty()
{
    return (head == nullptr);
}

template <typename T>
QString Queue<T>::print()
{
    QString result;
    Node<T>* temp = head;
    while (temp != nullptr)
    {
        result += QString::number(temp->data) + " ";
        temp = temp->next;
    }
    return result;
}


#endif // QUEUE_H
