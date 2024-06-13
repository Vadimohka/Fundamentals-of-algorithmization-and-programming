#ifndef TREENODE_H
#define TREENODE_H

template<typename T>
class TreeNode
{
public:
    TreeNode(long key, const T &val)
        : key(key)
        , data(val)
        , left_child(nullptr)
        , right_child(nullptr)
    {}
    TreeNode *left_child;
    TreeNode *right_child;
    long long key;
    T data;
};

#endif // TREENODE_H
