#ifndef NODE_H
#define NODE_H

enum Color { RED, BLACK };

template<typename K, typename V>
struct Node
{
    K key;
    V value;
    Color color = RED;
    Node *left;
    Node *right;
    Node *parent;

    Node(K key, V value)
        : key(key)
        , value(value)
        , left(nullptr)
        , right(nullptr)
        , parent(nullptr)
    {}
};

#endif // NODE_H
