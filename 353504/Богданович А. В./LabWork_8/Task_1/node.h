#ifndef NODE_H
#define NODE_H


template <typename T, typename U>
class Node
{
public:
    T key;
    U value;
    Node<T, U> *left;
    Node<T, U> *right;
    int height;
    Node<T, U> *parent;


    Node();
    Node(T key, U value);
    Node(Node const &node);






    ~Node();
private:

};

#endif // NODE_H
