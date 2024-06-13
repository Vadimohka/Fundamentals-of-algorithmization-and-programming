#ifndef QUEUE_H
#define QUEUE_H
#include <ctime>
#include <cstdlib>
#include "node.h"

class Queue {
public:
    Queue() : head(nullptr), tail(nullptr), size(0) {}

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void clear() {
        Node* current = head;
        while (current) {
            Node* temp = current;
            current = current->next;
            delete temp;
        }
        head = tail = nullptr;
        size = 0;
    }

    void enqueue(int data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        ++size;
    }

    int dequeue() {
        if (isEmpty()) {
            throw "Queue is empty";
        }
        int data = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        --size;
        return data;
    }

    bool isEmpty() const {
        return size == 0;
    }

    int getSize() const {
        return size;
    }

    int peek(int index) const {
        if (isEmpty() || index < 0 || index >= size) {
            throw "Invalid index";
        }
        Node* current = head;
        for (int i = 0; i < index; ++i) {
            current = current->next;
        }
        return current->data;
    }

    void fillMainQueueRandomly(int count) {
        srand(time(nullptr));
        for (int i = 0; i < count; ++i) {
            int num = rand() % 201 - 100;
            enqueue(num);
        }
    }

    void splitQueue(Queue& negativeQueue, Queue& positiveQueue) {
        while (!isEmpty()) {
            int num = dequeue();
            if (num < 0) {
                negativeQueue.enqueue(num);
            } else {
                positiveQueue.enqueue(num);
            }
        }
    }

private:
    Node* head;
    Node* tail;
    int size;
};

#endif // QUEUE_H
