#ifndef DEQUE_H
#define DEQUE_H
#include <stdexcept>
#include "iteratordeque.h"

template<typename T>
class Deque {
private:
    NodeDeque<T> *front;
    NodeDeque<T> *back;
    size_t deque_size = 0;
    size_t capacity = 0;

public:
    Deque() {}
    ~Deque() {}

    T &operator[](size_t index) {
        if (index < 0 || index >= deque_size) {
            throw std::out_of_range("Index out of range");
        }
        NodeDeque<T> *current = front;
        size_t count = 0;
        while (current != nullptr && count + current->count <= index) {
            count += current->count;
            current = current->next;
        }
        return current->data[index - count];
    }

    void push_back(const T &addItem){
        if (capacity == 0) {
            front = new NodeDeque<T>;
            back = front;
            back->data[0] = addItem;
            back->count++;
            capacity++;
        }
        else {
            if (back->count < 4) {
                back->data[back->count] = addItem;
                back->count++;
            }
            else {
                back->next = new NodeDeque<T>;
                back->next->prev = back;
                back = back->next;
                back->data[0] = addItem;
                back->count++;
                capacity++;
            }
        }

        deque_size++;
    }

    void push_front(const T &addItem){
        if (capacity == 0) {
            back = front = new NodeDeque<T>;
            front->data[0] = addItem;
            front->count++;
            capacity++;
        }
        else {
            if (front->count < 4) {
                for (int i = front->count - 1; i >= 0; --i) {
                    front->data[i + 1] = front->data[i];
                }
                front->data[0] = addItem;
                front->count++;
            }
            else {
                front->prev = new NodeDeque<T>;
                front->prev->next = front;
                front = front->prev;
                front->data[0] = addItem;
                front->count++;
                capacity++;
            }
        }

        deque_size++;
    }

    void pop_back() {
        if (!empty()) {
            --deque_size;
            if (back->count > 1) {
                --back->count;
            } else {
                NodeDeque<T> *tmp = back;
                back = back->prev;
                if (back) {
                    delete tmp;
                    back->next = nullptr;
                } else {
                    delete[] tmp->data;
                    delete tmp;
                    front = nullptr;
                    capacity = 0;
                    back = nullptr;
                }
            }
        }
    }

    void pop_front() {
        if (!empty()) {
            --deque_size;
            if (front->count > 1) {
                for (size_t i = 0; i < front->count - 1; ++i) {
                    front->data[i] = front->data[i + 1];
                }
                --front->count;
            } else {
                NodeDeque<T> *tmp = front;
                front = front->next;
                if (front) {
                    delete tmp;
                    front->prev = nullptr;
                } else {
                    delete[] tmp->data;
                    delete tmp;
                    back = nullptr;
                    capacity = 0;
                    front = nullptr;
                }
            }
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

    IteratorDeque<T> begin() {
        return IteratorDeque<T>(front, front != nullptr ? 0 : 0);
    }

    IteratorDeque<T> end() {
        return IteratorDeque<T>(nullptr, 0);
    }
};

#endif // DEQUE_H
