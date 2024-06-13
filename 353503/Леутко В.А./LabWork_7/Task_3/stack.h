#ifndef STACK_H
#define STACK_H

#include <cstddef>
#include <cstdint>

template<typename T>
class Stack
{
private:
    struct Node
    {
        Node *next;
        int64_t key;
        T value;
        Node(int64_t key, T value)
            : key(key)
            , value(value)
            , next(nullptr)
        {}
    };

    Node *top;

public:
    Stack();
    Stack(const Stack<T> &other);
    ~Stack();

    void push(int64_t key, T value);
    void pop(int64_t &key, T &value);
    void pop();
    void clear();
    bool empty();
};

#endif // STACK_H
