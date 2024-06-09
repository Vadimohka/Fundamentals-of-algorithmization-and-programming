#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <stdexcept>

#define size_t std::size_t

template <typename T>
class Queue {
protected:

    struct Node {
        template <typename ... Args>
        explicit Node(Args... args) : data(std::forward<Args>(args)...) {}

        Node* next = nullptr;
        Node* prev = nullptr;

        T data;
    };

    size_t _size = 0;
    Node* _first = nullptr;
    Node* _last = nullptr;
    // prev->last->...->first->next

    void clearLast(Node* lastNode) { // must be called when size == 1
        delete lastNode;
        _first = nullptr;
        _last = nullptr;
    }

public:
    Queue() = default;
    ~Queue() {
        clear();
    }


    Queue(const Queue&) = delete;
    Queue& operator=(const Queue&) = delete;


    template <typename TT>
    void push_front(TT&& value) {
        emplace_front(std::forward<TT>(value));
    }

    template <typename TT>
    void push_back(TT&& value) {
        emplace_back(std::forward<TT>(value));
    }


    void pop_front() {
        if (empty()) {
            return;
        }
        if (_first->prev != nullptr) {
            _first = _first->prev;
            delete _first->next;
            _first->next = nullptr;
        } else {
            clearLast(_first);
        }
        --_size;
    }

    void pop_back() {
        if (empty()) {
            return;
        }
        if (_last->next != nullptr) {
            _last = _last->next;
            delete _last->prev;
            _last->prev = nullptr;
        } else {
            clearLast(_last);
        }
        --_size;
    }


    T& front() {
        if (!empty()) {
            return _first->data;
        }
        throw std::runtime_error("Queue is empty");
    }

    T& back() {
        if (!empty()) {
            return _last->data;
        }
        throw std::runtime_error("Queue is empty");
    }


    template <typename ... Args>
    void emplace_front(Args&&... args) {
        if (empty()) {
            _first = new Node(std::forward<Args>(args)...);
            _last = _first;
        } else {
            _first->next = new Node(std::forward<Args>(args)...);
            _first->next->prev = _first;
            _first = _first->next;
        }
        ++_size;
    }

    template <typename ... Args>
    void emplace_back(Args&&... args) {
        if (empty()) {
            _first = new Node(std::forward<Args>(args)...);
            _last = _first;
        } else {
            _last->prev = new Node(std::forward<Args>(args)...);
            _last->prev->next = _last;
            _last = _last->prev;
        }
        ++_size;
    }


    void clear() {
        while (_first != nullptr) {
            Node* temp = _first;
            _first = _first->prev;
            delete temp;
        }
        _last = nullptr;
        _size = 0;
    }


    bool empty() {
        return _size == 0;
    }

    int size() {
        return _size;
    }
};

#endif // QUEUE_H
