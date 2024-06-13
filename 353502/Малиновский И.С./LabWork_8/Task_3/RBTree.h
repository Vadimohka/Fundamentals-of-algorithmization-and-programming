#ifndef RBTREE_H
#define RBTREE_H


template <typename K, typename V> class RBTree {
public:
    struct Node {
        K key;
        V val;
        Node *left, *right, *parent;
        explicit Node(int key, int val);
    };

private:

    Node *root;

}

#endif // RBTREE_H
