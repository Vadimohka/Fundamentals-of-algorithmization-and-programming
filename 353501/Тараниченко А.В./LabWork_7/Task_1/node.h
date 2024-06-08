#ifndef NODE_H
#define NODE_H


template <typename T>
class Node
{
public:
    Node();
    Node(T value);
    Node(Node const &n);
    ~Node();


    Node *nextNode;
    T _value;

private:

};

#endif // NODE_H
