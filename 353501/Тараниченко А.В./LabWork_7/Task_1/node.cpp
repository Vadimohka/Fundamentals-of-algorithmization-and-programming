#include "node.h"


template <typename T>
Node<T>::Node()
{
    _value = 0;
    Node *nextNode =nullptr;
}

template<typename T>
Node<T>::Node(T value)
{
    _value = value;
    Node *nextNode = nullptr;
}

template<typename T>
Node<T>::Node(const Node &n)
{
    this->_value = n._value;
    this->nextNode = n.nextNode;
}

template<typename T>
Node<T>::~Node()
{
}
