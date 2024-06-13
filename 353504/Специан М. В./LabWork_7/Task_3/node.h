#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
    Node(int key, const T value, Node* previous = nullptr)
    {
        this->key = key;
        this->value = value;
        this->previous = previous;
    }

    int key;
    T value;
    Node* previous;
};

#endif // NODE_H
