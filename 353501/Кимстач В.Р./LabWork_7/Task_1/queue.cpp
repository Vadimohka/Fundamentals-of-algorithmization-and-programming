
#include "queue.h"
#include <QDebug>
#include <QRandomGenerator>

Queue::Queue() : front(nullptr), rear(nullptr), size(0) {}

Queue::~Queue() {
    clear();
}

void Queue::enqueue(int value) {
    Node* newNode = new Node(value);
    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

int Queue::dequeue() {
    if (isEmpty()) {
        qDebug() << "Queue is empty";
        return -1;
    }
    int value = front->data;
    Node* temp = front;
    front = front->next;
    if (front == nullptr) {
        rear = nullptr;
    }
    delete temp;
    size--;
    return value;
}

int Queue::peek() {
    if (isEmpty()) {
        qDebug() << "Queue is empty";
        return -1;
    }
    return front->data;
}

bool Queue::isEmpty() {
    return size == 0;
}

int Queue::getSize() {
    return size;
}

void Queue::clear() {
    while (!isEmpty()) {
        dequeue();
    }
}

void Queue::makeMinFirst() {
    if (isEmpty()) {
        return;
    }

    Node* current = front;
    Node* minNode = front;

    // Находим минимальный элемент в очереди
    while (current != nullptr) {
        if (current->data < minNode->data) {
            minNode = current;
        }
        current = current->next;
    }


    if (minNode == front) {
        qDebug() << "Minimum element is already first";
        return;
    }


    if (minNode == rear) {
        rear = nullptr;
    }
    current = front;
    Node* prevNode = nullptr;
    while (current != minNode) {
        prevNode = current;
        current = current->next;
    }
    if (prevNode) {
        prevNode->next = minNode->next;
    } else {
        front = minNode->next;
    }


    minNode->next = front;
    front = minNode;
    if (!rear) {
        rear = minNode;
    }

    qDebug() << "Minimum element moved to the front";
}

void Queue::fillRandomQueue(int size) {
    clear();
    QRandomGenerator randomGenerator;
    for (int i = 0; i < size; i++) {
        enqueue(randomGenerator.bounded(100));
    }
}

Queue::Node* Queue::getNodeAt(int index) {
    if (index < 0 || index >= size) {
        qDebug() << "Invalid index";
        return nullptr;
    }

    Node* current = front;
    for (int i = 0; i < index; i++) {
        current = current->next;
    }
    return current;
}
