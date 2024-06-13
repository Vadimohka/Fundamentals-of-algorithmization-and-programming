#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "deque.h"

template <typename T>
Deque<T>::Deque() : head(nullptr), tail(nullptr), size(0) {}

template <typename T>
Deque<T>::~Deque() {
    while (head) {
        Node<T>* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
void Deque<T>::push_front(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (head == nullptr) {
        head = tail = newNode;
    } else {
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
    size++;
}

template <typename T>
void Deque<T>::push_back(T value) {
    Node<T>* newNode = new Node<T>(value);
    if (tail == nullptr) {
        head = tail = newNode;
    } else {
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

template <typename T>
T Deque<T>::pop_front() {
    if (head == nullptr) throw std::runtime_error("Deque is empty");
    Node<T>* temp = head;
    T value = head->data;
    head = head->next;
    if (head) head->prev = nullptr;
    else tail = nullptr;
    delete temp;
    size--;
    return value;
}

template <typename T>
T Deque<T>::pop_back() {
    if (tail == nullptr) throw std::runtime_error("Deque is empty");
    Node<T>* temp = tail;
    T value = tail->data;
    tail = tail->prev;
    if (tail) tail->next = nullptr;
    else head = nullptr;
    delete temp;
    size--;
    return value;
}

template <typename T>
bool Deque<T>::is_empty() const {
    return size == 0;
}

template <typename T>
int Deque<T>::get_size() const {
    return size;
}

template <typename T>
T Deque<T>::front() const {
    if (head == nullptr) throw std::runtime_error("Deque is empty");
    return head->data;
}

template <typename T>
T Deque<T>::back() const {
    if (tail == nullptr) throw std::runtime_error("Deque is empty");
    return tail->data;
}

template <typename T>
Node<T>* Deque<T>::get_head() const {
    return head;
}

template<typename T>
void Deque<T>::remove_between_max_min() {
    if (size < 3) return;

    Node<T>* current = head;
    Node<T>* maxNode = head;
    Node<T>* minNode = head;

    while (current) {
        if (current->data > maxNode->data) maxNode = current;
        if (current->data < minNode->data) minNode = current;
        current = current->next;
    }

    if (minNode->next == maxNode || maxNode->next == minNode) return;

    Node<T>* start;
    Node<T>* end;

    current = head;
    while (current) {
        if (current == minNode) {
            start = minNode;
            end = maxNode;
            break;
        } else if (current == maxNode) {
            start = maxNode;
            end = minNode;
            break;
        }
        current = current->next;
    }

    Node<T>* toDelete = start->next;
    while (toDelete != end) {
        Node<T>* nextNode = toDelete->next;
        delete toDelete;
        toDelete = nextNode;
        size--;
    }

    start->next = end;
    end->prev = start;
}

#endif // DEQUE_CPP
