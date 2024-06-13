#ifndef NODE_H
#define NODE_H

template<class T>
struct Node
{
    T value[4];

    int head;
    int tail;
    Node *next;
    Node *prev;

    Node() : next(nullptr), prev(nullptr), head(0), tail(0) {}
};
#endif // NODE_H
