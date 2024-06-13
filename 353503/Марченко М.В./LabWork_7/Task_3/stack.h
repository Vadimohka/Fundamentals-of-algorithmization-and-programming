#ifndef STACK_H
#define STACK_H

#include <stdexcept>

template <typename T>
class Stack {
private:
    static const int MAX_SIZE = 100;
    T data[MAX_SIZE];
    int top;

public:
    Stack() : top(-1) {}

    bool isEmpty() const {
        return top == -1;
    }

    bool isFull() const {
        return top == MAX_SIZE - 1;
    }

    void push(const T& item) {
        if (isFull()) {
            throw std::runtime_error("Stack overflow");
        }
        data[++top] = item;
    }

    T pop() {
        if (isEmpty()) {
            throw std::runtime_error("Stack underflow");
        }
        return data[top--];
    }

   T& at(int index) {
        if (index < 0 || index > top) {
            throw std::out_of_range("Index out of range");
        }
        return data[index];
    }

    int getSize() const {
        return top + 1;
    }
    void clear(){
        top = -1;
    }

    T peek() const {
        if (isEmpty()) {
            throw std::runtime_error("Stack underflow");
        }
        return data[top];
    }
};

#endif // STACK_H
