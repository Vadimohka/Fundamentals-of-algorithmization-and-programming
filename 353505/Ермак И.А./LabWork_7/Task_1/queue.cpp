#include "queue.h"

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) {
        throw std::runtime_error("Queue is empty");
    }

    Node* temp = head;
    int value = temp->data;
    head = head->next;

    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }

    delete temp;
    return value;
}

bool Queue::isEmpty() const {
    return head == nullptr;
}

void Queue::splitQueues(Queue& positiveQueue, Queue& negativeQueue) const {
    Node* current = head;
    while (current) {
        if (current->data < 0) {
            negativeQueue.enqueue(current->data);
        } else {
            positiveQueue.enqueue(current->data);
        }
        current = current->next;
    }
}

void Queue::printQueue() const {
    Node* current = head;
    while (current) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* Queue::getHead() const {
    return head;
}
