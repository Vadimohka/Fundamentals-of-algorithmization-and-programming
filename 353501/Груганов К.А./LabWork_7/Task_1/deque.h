#ifndef DEQUE_H
#define DEQUE_H

#include <cstddef>
#include <stdexcept>
template<typename T>
class Node
{
public:
    T value;
    Node *next;
    Node *prev;

    Node(T val)
        : value(val)
        , next(nullptr)
        , prev(nullptr)
    {}
};

template<typename T>
class Deque
{
public:
    Node<T> *front; //первый
    Node<T> *back;  //последний
    size_t size;

public:
    Deque()
        : front(nullptr)
        , back(nullptr)
        , size(0)
    {}

    ~Deque()
    {
        while (front != nullptr) {
            Node<T> *temp = front;
            front = front->next;
            delete temp;
            temp = nullptr;
        }
    }

    void push_front(T value)
    {
        Node<T> *node = new Node<T>(value);
        if (size == 0) {
            front = back = node;
        } else {
            node->next = front;
            front->prev = node;
            front = node;
        }
        size++;
    }

    void push_back(T value)
    {
        Node<T> *node = new Node<T>(value);
        if (size == 0) {
            front = back = node;
        } else {
            back->next = node;
            node->prev = back;
            back = node;
        }
        size++;
    }

    T pop_front()
    {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        Node<T> *temp = front;
        T value = front->value;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            back = nullptr;
        }
        delete temp;
        temp = nullptr;
        size--;
        return value;
    }

    T pop_back()
    {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        Node<T> *temp = back;
        T value = back->value;
        back = back->prev;
        if (back != nullptr) {
            back->next = nullptr;
        } else {
            front = nullptr;
        }
        delete temp;
        temp = nullptr;
        size--;
        return value;
    }

    T peek_front() const
    {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        return front->value;
    }

    T peek_back() const
    {
        if (size == 0) {
            throw std::out_of_range("Deque is empty");
        }
        return back->value;
    }

    bool is_empty() const { return size == 0; }

    size_t get_size() const { return size; }

    T at(size_t index) const
    {
        if (index >= size) {
            throw std::out_of_range("Index out of range");
        }
        Node<T> *current = front;
        for (size_t i = 0; i < index; i++) {
            current = current->next;
        }
        return current->value;
    }

    Node<T> *get_front() { return front; }

    void sort()
    {
        if (size < 2) {
            return;
        }

        bool swapped;
        do {
            swapped = false;
            Node<T> *current = front;
            while (current != nullptr && current->next != nullptr) {
                if (current->value > current->next->value) {
                    T temp = current->value;
                    current->value = current->next->value;
                    current->next->value = temp;
                    swapped = true;
                }
                current = current->next;
            }
        } while (swapped);
    }
};

#endif // DEQUE_H
