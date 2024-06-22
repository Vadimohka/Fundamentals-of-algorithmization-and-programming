#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
public:
    Node(QString, int);

    int key;
    QString value;

    Node* left;
    Node* right;

};

#endif // NODE_H
