#ifndef MAP_H
#define MAP_H

#include "rbt.h"

template <typename T, typename T1>
class Map : public RBT<T, T1> {
public:
    void add(T key, T1 value) {
        RBT<T, T1>::add(key, value);
    }

    void remove(T key) {
        RBT<T, T1>::remove(key);
    }

    T1 get(T key) {
        return RBT<T, T1>::operator[](key);
    }

    bool contains(T key) {
        return RBT<T, T1>::contains(key);
    }

    void clear() {
        RBT<T, T1>::clear();
    }

    T1& operator[](T key) {
        return RBT<T, T1>::operator[](key);
    }
protected:
    using RBT<T, T1>::findValueWithKey;
};

#endif // MAP_H
