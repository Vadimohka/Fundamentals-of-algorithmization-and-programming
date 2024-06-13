#ifndef MYTREE_H
#define MYTREE_H

#include "tree.h"
class MyTree : public Tree
{
public:
    using Tree::Tree;
    void deleteSubtreePerKey(int key);
};

#endif // MYTREE_H
