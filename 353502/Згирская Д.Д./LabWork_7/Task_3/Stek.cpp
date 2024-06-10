//
// Created by zgdarya on 5/30/24.
//

#include "Stek.h"

void Stek::push_back(int value) {
    if (!first && !last){
        first = new StekNode(value);
        last = first;
    } else {
        last->next = new StekNode(value);
        last->next->previous = last;
        last = last->next;
    }
    ++_size;
}

void Stek::pop_back() {
    if (first) {
        if (first != last)
            last->previous->next = nullptr;
        last = nullptr;
        --_size;
    }
}

int Stek::peek_back() {
    return last->value;
}

bool Stek::isEmpty() {
    if (first == nullptr)
        return true;
    return false;
}

StekNode *Stek::begin() {
    return first;
}

StekNode *Stek::end() {
    return last;
}

void Stek::clear() {
    while (!this->first) {
        this->pop_back();
    }
    _size = 0;
}

QString Stek::toString() {
    QString result;
    StekNode* current = this->first;
    for (int i = 0; i < _size && current != nullptr; ++i) {
        result += QString::number(current->value) + " ";
        current = current->next;
    }
    return result.trimmed();
}

Stek::Stek() {
    first = nullptr;
    last = nullptr;
}

int Stek::size() {
    return _size;
}

void Stek::operator=(Stek &other) {
    this->last = other.last;
    this->first = other.first;
    this->_size = other._size;
}
