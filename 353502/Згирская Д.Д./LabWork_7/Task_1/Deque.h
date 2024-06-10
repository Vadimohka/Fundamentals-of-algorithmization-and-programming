//
// Created by zgdarya on 5/30/24.
//

#ifndef L7_T1_DEQUE_H
#define L7_T1_DEQUE_H


#include "Node.h"

class Deque {
private:
    Node* first;
    Node* last;

    int _size;

public:
    Deque();
    int front();
    int back();
    bool isEmpty();
    Node* begin();
    Node* end();
    void push_back(int value);
    void pop_front();
    void deleteNegativeElements();
    int size();
};


#endif //L7_T1_DEQUE_H
