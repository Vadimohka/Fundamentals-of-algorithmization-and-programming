#ifndef NODE_H
#define NODE_H

template<typename T>
struct Node
{
    Node *next;
    int key;
    T value;
    Node(int key, T value)
        : key(key), value(value), next(nullptr)
    {}
};

#endif // NODE_H
