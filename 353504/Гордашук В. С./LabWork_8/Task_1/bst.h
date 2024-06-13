#ifndef BST_H
#define BST_H

#include <QDebug>
#include "node.h"

class BST
{
public:
    BST();
    void add(int v);
    void traversal();
    void remove(int v);
    void insertSubTree(Node *node);
    void removeSubTree(int v);
    Node* find(int v);
    Node* lca(int v1, int v2);
    Node *root = nullptr;

private:
    Node *add(Node *node, int v);
    void traversal(Node *node);
    Node* remove(Node* node, int v);
    Node* minValueNode(Node* node);
    Node* find(Node* node, int v);
    void removeSubTree(Node* node);
    Node* lca(Node* node, int v1, int v2);
};

#endif // BST_H
