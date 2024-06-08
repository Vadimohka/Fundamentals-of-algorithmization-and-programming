#ifndef DEQUE_H
#define DEQUE_H

#include "node.h"
#include <QTextEdit>
#include <stdexcept>

class Deque {
private:
    Node* head;
    Node* tail;

public:
    Deque() : head(nullptr), tail(nullptr) {}

    ~Deque() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void enqueue(const std::string& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }

    std::string dequeue() {
        if (!head) {
            throw std::runtime_error("Queue is empty");
        }
        Node* temp = head;
        std::string data = head->data;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        } else {
            tail = nullptr;
        }
        delete temp;
        return data;
    }

    void convertToRing() {
        if (head && tail) {
            head->prev = tail;
            tail->next = head;
        }
    }

    void displayQueue(QTextEdit* textEdit) const {
        textEdit->clear();
        Node* current = head;
        while (current) {
            textEdit->append(QString::fromStdString(current->data));
            current = current->next;
            if (current == head) break; // Для кольцевой очереди
        }
    }
};

#endif // DEQUE_H
