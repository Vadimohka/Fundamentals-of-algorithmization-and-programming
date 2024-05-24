#ifndef D73026E7_E25E_4161_AD63_949EDF17F48F
#define D73026E7_E25E_4161_AD63_949EDF17F48F


#include "RBTree.h"
#include <cstddef>
#include <cstdint>

template <typename T>
class Set {
    RBTree<T, char> tree;

    void insert(const T& t){
        tree.insert(t, 0);
    }

    bool conatins(const T& t){
        return tree.contains(t);
    }

    bool remove(const T& t){
        return tree.remove(t);
    }

    size_t size(){
        return tree.size();
    }

};

#endif /* D73026E7_E25E_4161_AD63_949EDF17F48F */
