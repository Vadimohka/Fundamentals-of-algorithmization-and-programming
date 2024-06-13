#ifndef DEQUE_H
#define DEQUE_H

#include <stdexcept>

#include "node.h"

template <typename T>
class Deque {

public:
    Deque();
    ~Deque();

    void push_front(T value);
    void push_back(T value);
    T pop_front();
    T pop_back();
    bool is_empty() const;
    int get_size() const;
    T front() const;
    T back() const;
    Node<T>* get_head() const;
    void remove_between_max_min();

private:
    Node<T>* head;
    Node<T>* tail;
    int size;
};

#endif // DEQUE_H
