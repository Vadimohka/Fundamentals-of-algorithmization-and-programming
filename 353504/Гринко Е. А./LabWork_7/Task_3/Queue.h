#ifndef QUEUE_H
#define QUEUE_H

#include <memory>
#include <stdexcept>

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
    Queue() : _first(nullptr), _last(nullptr) {};

    ~Queue() {
        clear();
    }

    Queue(const Queue& other) {
        Node* temp = other._last;
        _size = 0;
        while (temp != nullptr) {
            emplace_front(temp->data);
            temp = temp->next;
        }
    }

    Queue& operator=(const Queue& other) {
        if (this != &other) {
            clear();
            _size = 0;
            Node* temp = other._last;
            while (temp != nullptr) {
                emplace_front(temp->data);
                temp = temp->next;
            }
        }
        return *this;
    }

    Queue(Queue&& other) noexcept : _size(other._size), _first(other._first), _last(other._last) {
        other._size = 0;
        other._first = nullptr;
        other._last = nullptr;
    }

    Queue& operator=(Queue&& other) noexcept {
        if (this != &other) {
            clear();
            _size = other._size;
            _first = other._first;
            _last = other._last;
            other._size = 0;
            other._first = nullptr;
            other._last = nullptr;
        }
        return *this;
    }


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


    bool empty() const {
        return _size == 0ULL;
    }

    int size() const {
        return _size;
    }
};

#endif // QUEUE_H
