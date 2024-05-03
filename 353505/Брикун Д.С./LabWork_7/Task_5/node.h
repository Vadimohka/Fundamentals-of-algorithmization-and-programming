#ifndef NODE_H
#define NODE_H

template<class T>
struct Node {
    T data[4];
    int first;
    int last;
    Node *next;
    Node *prev;

    Node() : next(nullptr), prev(nullptr), first(0), last(0) {}
};
#endif // NODE_H
