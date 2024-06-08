#ifndef TREECHILD_H
#define TREECHILD_H

#include "tree.h"
#include "tree.cpp"

template <typename T, typename U>
class TreeChild : public Tree<T, U>
{
public:
    TreeChild();

    int leavesCount(Node<T, U>* node);
    int leavesCount();
};

#endif // TREECHILD_H
