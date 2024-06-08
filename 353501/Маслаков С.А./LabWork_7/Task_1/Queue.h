
#ifndef LAB7_QUEUE_H
#define LAB7_QUEUE_H
#include <iostream>
using namespace std;
template <typename T>
struct Node {
    T data;
    Node *prev, *next;
    static Node *getnode(T data) {
        Node *newNode = new Node;
        newNode->data = data;
        newNode->prev = newNode->next = nullptr;
        return newNode;
    }
};

template <typename T>
class Queue {
public:
    Node<T> *front;
    Node<T> *back;
    int Size;
    Queue() {
        front = back = nullptr;
        Size = 0;
    }
    void pushFront(T data) {
        Node<T> *newNode = Node<T>::getnode(data);
        if (newNode == nullptr)
            cout << "OverFlow\n";
        else {
            if (front == nullptr)
                back = front = newNode;
            else {
                newNode->next = front;
                front->prev = newNode;
                front = newNode;
            }
            Size++;
        }
    }
    void pushBack(T data) {
        Node<T> *newNode = Node<T>::getnode(data);
        if (newNode == nullptr) cout << "OverFlow\n";
        else {
            if (back == nullptr)
                front = back = newNode;
            else {
                newNode->prev = back;
                back->next = newNode;
                back = newNode;
            }
            Size++;
        }
    }
    void popFront() {
        if (isEmpty())
            cout << "UnderFlow\n";
        else {
            Node<T> *temp = front;
            front = front->next;
            if (front == nullptr)
                back = nullptr;
            else
                front->prev = nullptr;
            delete temp;
            Size--;
        }
    }
    void popBack() {
        if (isEmpty())
            cout << "UnderFlow\n";
        else {
            Node<T> *temp = back;
            back = back->prev;
            if (back == nullptr)
                front = nullptr;
            else
                back->next = nullptr;
            delete temp;
            Size--;
        }
    }
    T getFront() {
        if (isEmpty())
            return -1;
        return front->data;
    }
    T getBack() {
        if (isEmpty())
            return -1;
        return back->data;
    }
    int size() { return Size; }
    bool isEmpty() { return (front == nullptr); }
    void clear() {
        back = nullptr;
        while (front != nullptr) {
            Node<T> *temp = front;
            front = front->next;
            delete temp;
        }
        Size = 0;
    }
    void swapMaxMin() {
        if (isEmpty() || size() == 1)
            return;

        Node<T> *maxNode = front;
        Node<T> *minNode = back;
        for (Node<T> *curr = front; curr != nullptr; curr = curr->next) {
            if (curr->data > maxNode->data)
                maxNode = curr;
            if (curr->data < minNode->data)
                minNode = curr;
        }
        if (maxNode == front)
            front = minNode;
        else if (minNode == front)
            front = maxNode;
        if (maxNode == back)
            back = minNode;
        else if (minNode == back)
            back = maxNode;
        Node<T>* temp;
        temp = maxNode->next;
        maxNode->next = minNode->next;
        minNode->next = temp;
        if (maxNode->next != nullptr)
            maxNode->next->prev = maxNode;
        if (minNode->next != nullptr)
            minNode->next->prev = minNode;
        temp = maxNode->prev;
        maxNode->prev = minNode->prev;
        minNode->prev = temp;
        if (maxNode->prev != nullptr)
            maxNode->prev->next = maxNode;
        if (minNode->prev != nullptr)
            minNode->prev->next = minNode;
    }
};

#endif //LAB7_QUEUE_H
