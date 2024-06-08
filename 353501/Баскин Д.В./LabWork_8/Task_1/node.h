#ifndef NODE_H
#define NODE_H

template<typename T>
class Node
{
public:
    long long key;
    T value;
    Node<T> *left;
    Node<T> *right;

    Node(long long key, const T& value)
    {
        this->key = key;
        this->value = value;
        left = nullptr;
        right = nullptr;
    }

    ~Node()
    {
        if (left)
        {
            delete left;
        }
        if (right)
        {
            delete right;
        }
    }
};

#endif // NODE_H
