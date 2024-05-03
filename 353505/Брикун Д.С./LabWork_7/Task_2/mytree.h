#ifndef MYTREE_H
#define MYTREE_H

#include "tree.h"
class MyTree : public Tree
{
private:
    void nodesPerLevel(TreeNode*, QVector<int> &, int);
public:
    using Tree::Tree;
    QVector<int> nodesPerLevel();
};

#endif // MYTREE_H
