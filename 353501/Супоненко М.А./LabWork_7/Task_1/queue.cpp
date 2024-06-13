#include "queue.h"
#include <iostream>
#include <unordered_set>

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::enqueue(int val) {
    Node* newNode = new Node(val);
    if (tail) {
        tail->next = newNode;
        newNode->prev = tail;
    }
    tail = newNode;
    if (!head) {
        head = newNode;
    }
}

int Queue::dequeue() {
    if (isEmpty()) return -1; // Or throw an exception
    int retVal = head->data;
    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    delete temp;
    return retVal;
}

bool Queue::isEmpty() const {
    return head == nullptr;
}

void Queue::removeDuplicates() {
    if (isEmpty()) return;

    std::unordered_set<int> seen;
    Node* current = head;

    while (current) {
        if (seen.find(current->data) != seen.end()) {
            Node* temp = current;
            if (temp->prev) {
                temp->prev->next = temp->next;
            }
            if (temp->next) {
                temp->next->prev = temp->prev;
            }
            if (temp == head) {
                head = temp->next;
            }
            if (temp == tail) {
                tail = temp->prev;
            }
            current = current->next;
            delete temp;
        } else {
            seen.insert(current->data);
            current = current->next;
        }
    }
}

void Queue::display() const {
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
