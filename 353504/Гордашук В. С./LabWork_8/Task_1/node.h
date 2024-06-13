#ifndef NODE_H
#define NODE_H

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    Node *parent;
    Node(int v)
    {
        key = v;
        left = right = parent = nullptr;
    }
};

#endif // NODE_H
