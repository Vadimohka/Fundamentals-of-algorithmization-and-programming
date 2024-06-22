#include "doublylinkedqueue.h"

DoublyLinkedQueue::DoublyLinkedQueue() : head(nullptr), tail(nullptr), current(nullptr), totalNodes(0) {}

void DoublyLinkedQueue::push_back(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        tail = newNode;
        current = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    totalNodes++;
}

void DoublyLinkedQueue::push_front(int value) {
    Node* newNode = new Node(value);
    if (!head) {
        head = newNode;
        tail = newNode;
        current = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    totalNodes++;
}

int DoublyLinkedQueue::pop_back() {
    if (!tail) return -1;
    int value = tail->data;
    Node* temp = tail;
    tail = tail->prev;
    if (tail) {
        tail->next = nullptr;
    } else {
        head = nullptr;
    }
    if (current == temp) {
        current = tail;
    }
    delete temp;
    totalNodes--;
    return value;
}

int DoublyLinkedQueue::pop_front() {
    if (!head) return -1;
    int value = head->data;
    Node* temp = head;
    head = head->next;
    if (head) {
        head->prev = nullptr;
    } else {
        tail = nullptr;
    }
    if (current == temp) {
        current = head;
    }
    delete temp;
    totalNodes--;
    return value;
}

void DoublyLinkedQueue::convertToRing() {
    if (head && tail) {
        tail->next = head;
        head->prev = tail;
    }
}

void DoublyLinkedQueue::moveForward() {
    if (current) {
        current = current->next;
    }
}

void DoublyLinkedQueue::moveBackward() {
    if (current) {
        current = current->prev;
    }
}

int DoublyLinkedQueue::getCurrentValue() const {
    return current ? current->data : -1;
}

Node *DoublyLinkedQueue::getHead() const {
    return head;
}

int DoublyLinkedQueue::getTotalNodes() const {
    return totalNodes;
}

DoublyLinkedQueue::~DoublyLinkedQueue() {
    if (!head) return;
    Node* temp = head;
    do {
        Node* next = temp->next;
        delete temp;
        temp = next;
    } while (temp && temp != head);
}
