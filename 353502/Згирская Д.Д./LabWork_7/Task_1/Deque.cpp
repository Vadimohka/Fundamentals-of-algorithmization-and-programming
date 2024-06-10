//
// Created by zgdarya on 5/30/24.
//

#include "Deque.h"

int Deque::front() {
    return first->value;
}

int Deque::back() {
    return last->value;
}

void Deque::push_back(int value) {
    if (!first && !last){
        first = new Node(value);
        last = first;
    } else {
        last->next = new Node(value);
        last->next->previous = last;
        last = last->next;
    }
    ++_size;
}

void Deque::pop_front() {
    if (first) {
        first = first->next;
        if (first)
            first->previous = nullptr;
        else
            last = first;
    }
    --_size;
}

void Deque::deleteNegativeElements() {
    Node* stop = first;
    while (first->next != stop) {
        if (first->value >= 0)
            this->push_back(first->value);
        pop_front();
    }
}

Deque::Deque() : _size(0) , first(nullptr) , last(nullptr) {
}

bool Deque::isEmpty() {
    if (first == nullptr)
        return true;
    return false;
}

Node *Deque::begin() {
    return first;
}

Node *Deque::end() {
    return last;
}

int Deque::size() {
    return _size;
}
