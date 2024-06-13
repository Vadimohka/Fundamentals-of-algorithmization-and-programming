#ifndef NODE_H
#define NODE_H

#include <QString>

class Node
{
public:
    Node(int key, const QString value, Node* left = nullptr, Node* right = nullptr)
    {
        this->key = key;
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int key;
    QString value;
    Node* left;
    Node* right;
};

#endif // NODE_H
