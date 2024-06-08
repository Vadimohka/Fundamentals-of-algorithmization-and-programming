#ifndef SET_H
#define SET_H
#include "rbt.h"

template <typename T>
class Set : public RBT<T, int> {
public:
    void add(T key) {
        RBT<T, int>::add(key, 0);
    }

    void remove(T key) {
        RBT<T, int>::remove(key);
    }

    bool contains(T key) {
        return RBT<T, int>::contains(key);
    }

    void clear() {
        RBT<T, int>::clear();
    }

protected:
    using RBT<T, int>::findValueWithKey;
    using RBT<T, int>::operator[];
};


#endif // SET_H
