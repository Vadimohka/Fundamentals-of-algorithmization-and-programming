#ifndef NODE_H
#define NODE_H

class Node {
public:
    int value;
    Node* left;
    Node* right;

    Node(int val) : value(val), left(nullptr), right(nullptr) {}
};

#endif // NODE_H
