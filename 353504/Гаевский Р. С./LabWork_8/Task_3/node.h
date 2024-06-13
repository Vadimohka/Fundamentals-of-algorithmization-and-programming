#ifndef NODE_H
#define NODE_H

#include <utility>
#include <memory>

template<class K, class V>
struct Node {
    std::pair<const K, V> data;
    std::shared_ptr<Node<K, V>> left;
    std::shared_ptr<Node<K, V>> right;
    std::weak_ptr<Node<K, V>> parent;
    bool color;

    Node(const K& key, const V& val)
        : data(key, val), left(nullptr), right(nullptr), parent(), color(false) {}
};

#endif // NODE_H
