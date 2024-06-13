#include "node.h"

Node::Node(int key, QString value)
{
    this->key = key;
    this->value = value;
    height = 0;
    right = nullptr;
    left = nullptr;
    parent = nullptr;
}

Node::Node(const Node &node)
{
    this->key = node.key;
    this->value = node.value;
    this->right = node.right;
    this->left = node.left;
    this->parent = node.parent;
    height = node.height;
}