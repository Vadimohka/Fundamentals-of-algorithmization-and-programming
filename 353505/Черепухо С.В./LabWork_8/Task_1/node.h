#ifndef NODE_H
#define NODE_H

template <typename T>
struct Node {
    long key;
    Node<T> *left;
    Node<T> *right;
    T data;

    Node(long key, const T &val) : key(key), data(val) {
        left = nullptr;
        right = nullptr;
    }

    ~Node() {
        if (left != nullptr)
            delete left;
        if (right != nullptr)
            delete right;
    }
};

#endif // NODE_H
