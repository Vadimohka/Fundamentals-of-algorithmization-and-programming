#ifndef STACK_H
#define STACK_H

#include "Queue.h"

template <class T>
class Stack {
private:
    Queue<T> _data;

public:
    Stack() : _data(Queue<T>()) {}

    Stack(const Stack& other) : _data(other._data) {}

    Stack& operator=(const Stack& other) {
        if (this != &other) {
            _data = other._data;
        }
        return *this;
    }

    Stack(Stack&& other) noexcept : _data(std::move(other._data)) {}

    Stack& operator=(Stack&& other) noexcept {
        if (this != &other) {
            _data = std::move(other._data);
        }
        return *this;
    }

    template <class TT>
    void add(TT&& value) {
        _data.push_back(std::forward<TT>(value));
    }

    template <class ... Args>
    void emplace(Args&& ... value) {
        _data.emplace_back(std::forward<Args>(value)...);
    }

    const T& top() const {
        return _data.back();
    }

    T& top() {
        return _data.back();
    }

    void pop() {
        _data.pop_back();
    }

    size_t size() {
        return _data.size();
    }

    bool empty() const {
        return _data.empty();
    }

    void clear() {
        _data.clear();
    }
};

#endif // STACK_H
