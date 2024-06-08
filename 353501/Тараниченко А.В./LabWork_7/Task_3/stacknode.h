#ifndef STACKNODE_H
#define STACKNODE_H

template <typename T>
class StackNode {
public:
    T data;
    StackNode<T>* next;

    StackNode();
    StackNode(T value);
    StackNode(const StackNode& n);
    ~StackNode();
};

#endif
