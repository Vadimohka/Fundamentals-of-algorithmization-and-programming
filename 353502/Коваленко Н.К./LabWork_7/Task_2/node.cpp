#include "node.h"

Node::Node(QString value, int key)
{
    left = nullptr;
    right = nullptr;

    this -> key = key;
    this -> value = value;
}
