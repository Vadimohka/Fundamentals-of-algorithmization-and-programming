#ifndef MYMAP_H
#define MYMAP_H

#include<RedBlackTree.h>

template<typename Key, typename Data>
class Map {

private:

    RedBlackTree<Key, Data> tree;

public:

    void insert(const Key& key, const Data& data){
        tree.insert(key, data);
    }

    bool remove(const Key& key){
        tree.deleteNode(key);
    }

    Data getValue(const Key& key) {
        return tree.searchTree(key);
    }

    void inorderTraversal() {
        tree.inorderTraversal();
    }

    void preorderTraversal() {
        tree.preorderTraversal();
    }

    void postorderTraversal() {
        tree.postorderTraversal();
    }

    Key getMaxKey() const{
        return tree.maximum();
    }

    Key getMinKey() const{
        return tree.minimum();
    }

    void clear(){
        tree.clear();
    }

    bool isEmpty() const{
        return tree.isEmpty();
    }
    bool contains(const Key& key){
        tree.searchTree(key);
    }

    size_t size(){
        return tree.size();
    }
};
#endif // MYMAP_H
