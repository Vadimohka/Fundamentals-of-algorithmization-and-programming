#ifndef NODE_H
#define NODE_H

template<typename t>

class Node
{
public:
    Node() {};

    Node* next = nullptr;
    Node* prev = nullptr;

    int count = 0;

    t* data = new t [4];
};

#endif // NODE_H
