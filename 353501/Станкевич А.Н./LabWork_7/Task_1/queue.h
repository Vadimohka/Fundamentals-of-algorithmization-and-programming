#pragma once

#include <stdexcept>
#include <QString>
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int value) : data(value), next(nullptr), prev(nullptr) {}
};

class Queue
{
private:
    Node *head;
    Node *tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}


    bool isEmpty() const
    {
        return head == nullptr;
    }
    int end()
    {
        if (!head)
            throw std::out_of_range("Queue is empty");

        Node* temp = tail;
        int value = temp->data;

        if (head == tail)
        {
            head = tail = nullptr;
        }
        else
        {
            tail = temp->prev;
            tail->next = nullptr;
        }

        delete temp;
        return value;
    }


    void splitQueue(Queue& negatives, Queue& positives) {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            if (current->data < 0) {
                current->prev = current->next = nullptr;
                negatives.enqueue(current);
            } else {
                current->prev = current->next = nullptr;
                positives.enqueue(current);
            }
            current = next;
        }
        head = tail = nullptr;
    }
    QString output() const
    {
        QString result;
        Node* temp = head;

        while (temp)
        {
            result += QString::number(temp->data);
            if (temp->next)
                result += " ";
            temp = temp->next;
        }

        return result.trimmed();
    }


    void enqueue(Node* newNode)
    {
        if (tail)
        {
            newNode->prev = tail;
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            head = tail = newNode;
        }
    }
    ~Queue() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }
};
