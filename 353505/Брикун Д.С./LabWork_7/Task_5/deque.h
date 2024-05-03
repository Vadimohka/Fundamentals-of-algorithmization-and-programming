#ifndef DEQUE_H
#define DEQUE_H

#include "iterator.h"
#include "node.h"
#include <cstddef>
template<typename T>
class Deque {
private:
    Node<T> *first;
    Node<T> *last;
    size_t deque_size;

public:
    Deque() : first(nullptr), last(nullptr), deque_size(0) {}

    ~Deque() {
        clear();
    }

    void push_back(const T &value) {
        if (last == nullptr || last->last == 3) {
            Node<T> *newNode = new Node<T>();
            if (empty()) {
                newNode->next = newNode;
                newNode->prev = newNode;
                first = last = newNode;
            } else {
                last->next = newNode;
                newNode->prev = last;
                newNode->next = first;
                first->prev = newNode;
                last = newNode;
            }
        } else
            ++last->last;
        last->data[last->last] = value;
        deque_size++;
    }

    void pop_back() {
        if (!empty()) {
            --deque_size;
            if (last != nullptr) --last->last;
            if (last != nullptr && last->last == -1) {
                Node<T> *temp = last;
                if (last == first) {
                    first = last = nullptr;
                } else {
                    last = last->prev;
                    if (last != nullptr)
                        last->next = first;
                    first->prev = last;
                    //                    --last->last;
                }
                delete temp;
            }
        }
    }

    void pop_front() {
        if (!empty()) {
            --deque_size;
            if (first != nullptr) ++first->first;
            if (first != nullptr && first->first == 4) {
                Node<T> *temp = first;
                if (first == last) {
                    first = last = nullptr;
                } else {
                    first = first->next;
                    if (first != nullptr)
                        first->prev = last;
                    last->next = first;
                }
                delete temp;
            }
        }
    }

    void push_front(const T &value) {
        if (first == nullptr || first->first == 0) {
            Node<T> *newNode = new Node<T>();
            if (empty()) {
                newNode->data[0] = value;
                newNode->next = newNode;
                newNode->prev = newNode;
                first = last = newNode;
            } else {
                newNode->data[3] = value;
                newNode->first = 3;
                newNode->last = 3;
                newNode->prev = last;
                newNode->next = first;
                first->prev = newNode;
                last->next = newNode;
                first = newNode;
            }
            ++deque_size;
        } else {
            --(first->first);
            first->data[first->first] = value;
            deque_size++;
        }
    }


    void clear() {
        while (!empty()) {
            pop_back();
        }
    }

    size_t size() const {
        return deque_size;
    }

    bool empty() const {
        return deque_size == 0;
    }

    Iterator<T> begin() {
        return Iterator(first != nullptr ? first : nullptr, first != nullptr ? first->first : 0);
    }

    Iterator<T> end() {
        if (last != nullptr)
            return ++Iterator<T>(last, last->last);
        else
            return Iterator<T>(nullptr, 0);
    }
};


#endif // DEQUE_H
