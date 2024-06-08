#ifndef TREE_NODE_H
#define TREE_NODE_H

#include <QString>

class tree_node
{
public:
    tree_node(int key, QString data);
    tree_node *left;
    tree_node *right;
    int key;
    QString data;
};

#endif // TREE_NODE_H
