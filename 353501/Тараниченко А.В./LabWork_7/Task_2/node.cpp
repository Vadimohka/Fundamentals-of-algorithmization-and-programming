#include "node.h"


template<typename T, typename U>
Node<T, U>::Node(T key, U value)
{
    this->key = key;
    this->value = value;
    height = 0;
    right = nullptr;
    left = nullptr;
}

template<typename T, typename U>
Node<T, U>::Node(const Node &node)
{
    this->key = node.key;
    this->value = node.value;
    this->right = node.right;
    this->left = node.left;
    height = node.height;
}

template<typename T, typename U>
Node<T, U>::~Node()
{
    right = nullptr;
    left = nullptr;
    height = 0;
}
