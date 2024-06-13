#ifndef TREE_NODE_H
#define TREE_NODE_H

template <typename T>
class TreeNode {
public:
    TreeNode(long key, const T &val) : key(key), data(val), leftchild(nullptr), rightchild(nullptr) {}
    TreeNode* leftchild;
    TreeNode* rightchild;
    long long key;
    T data;
};

#endif // TREE_NODE_H
