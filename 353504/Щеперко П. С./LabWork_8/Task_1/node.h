#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
public:
    int key;
    QString value;
    Node *left;
    Node *right;
    int height;
    Node *parent;
    Node();
    Node(int key, QString value);
    Node(Node const &node);
};

#endif // NODE_H
