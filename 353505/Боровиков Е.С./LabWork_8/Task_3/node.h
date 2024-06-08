#ifndef NODE_H
#define NODE_H
#include <memory>
#include <QPair>

template<class T, class T1>
struct Node {
    Node(T nKey, T1 nValue) : data(QPair<const T, T1>(nKey, nValue)), color(0), parent(), left(nullptr), right(nullptr), next(nullptr), prev(nullptr) {}
    Node() : data(), color(0), parent(), left(nullptr), right(nullptr), next(nullptr), prev(nullptr) {}

    std::shared_ptr<Node<T, T1>> left, right;
    std::weak_ptr<Node<T, T1>> parent;
    std::shared_ptr<Node<T, T1>> next, prev;
    bool color;
    QPair<const T, T1> data;

    T key() const { return data.first; }
    T1& value() { return data.second; }
    const T1& value() const { return data.second; }
};

#endif // NODE_H
