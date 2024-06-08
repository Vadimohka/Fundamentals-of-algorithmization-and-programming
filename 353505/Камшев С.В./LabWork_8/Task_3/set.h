#ifndef SET_H
#define SET_H

#include "rbtree.h"
#include <stdexcept>

template <typename T>
class Set : public RBTree<T, int> {
public:
    void insert(T key) {
        RBTree<T, int>::insert(key, 0);
    }

    void erase(T key) {
        RBTree<T, int>::erase(key);
    }

    bool contains(T key) {
        return RBTree<T, int>::containsKey(key);
    }

    void clear() {
        RBTree<T, int>::clear();
    }

    T getMax() {
        if (RBTree<T, int>::isEmpty()) throw std::runtime_error("The tree is empty");
        else return RBTree<T, int>::getMax();
    }
};

#endif // SET_H
