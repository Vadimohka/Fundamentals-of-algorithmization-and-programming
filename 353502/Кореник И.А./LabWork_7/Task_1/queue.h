#ifndef QUEUE_H
#define QUEUE_H
#include <iostream>
#include <QVector>
template <typename T>
struct Node {
    T data;
    Node* prev;
    Node* next;

    Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
};


template <typename T>
class Queue {
public:
    Queue() : head(nullptr), tail(nullptr) {}

    bool is_empty() const {
        return head == nullptr;
    }

    void append(const T& data) {
        Node<T>* new_node = new Node<T>(data);
        if (is_empty()) {
            head = new_node;
            tail = new_node;
        } else {
            tail->next = new_node;
            new_node->prev = tail;
            tail = new_node;
        }
    }

    void push_front(const T& data) {
        Node<T>* new_node = new Node<T>(data);
        if (is_empty()) {
            head = new_node;
            tail = new_node;
        } else {
            new_node->next = head;
            head->prev = new_node;
            head = new_node;
        }
    }

    T pop_front() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T popped_data = head->data;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        return popped_data;
    }

    T pop_back() {
        if (is_empty()) {
            throw std::runtime_error("Queue is empty");
        }
        T popped_data = tail->data;
        if (head == tail) {
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tail->prev;
            tail->next = nullptr;
        }
        return popped_data;
    }

    void print_list() const {
        Node<T>* current = head;
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
    QVector<T> toVector(){
        QVector<T> result;
        Node<T> *cur = head;
        while (cur) {
            result.push_back(cur->data);
            cur = cur->next;
        }
        return result;
    }
    bool empty() const { return !head; }
    void clear() {
        while (!empty()) pop_front();
    }


private:
    Node<T>* head;
    Node<T>* tail;
};



#endif // QUEUE_H
