#include "queue.h"

Queue::Queue(): sz(0), head(nullptr), tail(nullptr) {}

Queue::~Queue()
{
    while(size() > 0)
    {
        delFromEnd();
    }
}

bool Queue::isEmpty() const
{
    return sz == 0;
}

int Queue::size() const
{
    return sz;
}

void Queue::delFromBegin()
{
    if (isEmpty())
    {
        throw "Invalid delete";
    }
    else
    {
        Node* temp = head;
        head = head->next;
        delete temp;
        --sz;
    }
}

void Queue::delFromEnd()
{
    if (isEmpty())
    {
        throw "Invalid delete";
    }
    else
    {
        Node* temp = tail;
        tail = tail->prev;
        delete temp;
        --sz;
    }
}

int Queue::peekInBegin()
{
    if (isEmpty())
    {
        throw "Invalid peek";
    }
    else
    {
        return head->data;
    }
}

int Queue::peekInEnd()
{
    if (isEmpty())
    {
        throw "Invalid peek";
    }
    else
    {
        return tail->data;
    }
}

void Queue::clear()
{
    while(size() > 0)
    {
        delFromEnd();
    }

    head = nullptr;
    tail = nullptr;
}

QString Queue::toString()
{
    QString ans = "";
    Node* temp = head;
    while (temp->next != nullptr)
    {
        ans += QString::number(temp->data) + " ";
        temp = temp->next;
    }

    ans += QString::number(temp->data);
    return ans;
}

void Queue::addInEnd(int data)
{
    Node* newNode = new Node(data);

    if (isEmpty())
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

    ++sz;
}

void Queue::addInBegin(int data)
{
    Node* newNode = new Node(data);

    if (isEmpty())
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
