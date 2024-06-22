#ifndef NODE_H
#define NODE_H

#include <QString>

struct Node {
    int key;
    QString data;
    Node* left;
    Node* right;
};

#endif // NODE_H
