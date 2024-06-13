#include "queue.h"

Queue::Queue() : head(nullptr), tail(nullptr) {}

Queue::~Queue() {
    clear();
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
        throw std::out_of_range("Queue is empty");
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

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::bubbleSort() {
    if (isEmpty() || head == tail) return;

    bool swapped;
    do {
        swapped = false;
        Node* current = head;
        while (current->next != nullptr) {
            if (current->data > current->next->data) {
                std::swap(current->data, current->next->data);
                swapped = true;
            }
            current = current->next;
        }
    } while (swapped);
}

void Queue::print() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

Node* Queue::getHead() const {
    return head;
}
