#ifndef NODE_H
#define NODE_H

#include <memory>

template<typename T>
class Node
{
public:
    T value;
    std::weak_ptr<Node<T>> parent;
    std::shared_ptr<Node<T>> left;
    std::shared_ptr<Node<T>> right;
};

#endif // NODE_H
