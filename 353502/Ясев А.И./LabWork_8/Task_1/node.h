#ifndef NODE_H
#define NODE_H

#include <QString>

struct Node {
    int key;
    QString value;
    Node* left;
    Node* right;

    Node(int key, const QString& value) : key(key), value(value), left(nullptr), right(nullptr) {}
};

#endif // NODE_H
