#ifndef MAP_H
#define MAP_H

#include "rbtree.h"
#include <limits.h>

template <typename K, typename V>
class Map : public RBTree<K, V> {
public:
    void insert(K key, V value) {
        RBTree<K, V>::insert(key, value);
    }

    void erase(K key) {
        RBTree<K, V>::erase(key);
    }

    V get(K key) {
        if (RBTree<K, V>::containsKey(key)) return RBTree<K, V>::get(key);
        return INT_MIN;
    }

    bool contains(K key) {
        return RBTree<K, V>::containsKey(key);
    }

    void clear() {
        RBTree<K, V>::clear();
    }
};

#endif // MAP_H
