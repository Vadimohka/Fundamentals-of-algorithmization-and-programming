#ifndef MYSET_H
#define MYSET_H

#include<RedBlackTree.h>

template<typename K>
class Set{
private:
    RedBlackTree<K, K> tree;
public:

    Set() = default;

    ~Set() = default;

    void insert(const K& key){
        tree.insert(key, key);
    }

    bool remove(const K& key){
        tree.deleteNode(key);
    }

    bool contains(const K& key){
        tree.searchTree(key);
    }

    size_t size(){
        return tree.size();
    }
};
#endif // MYSET_H
