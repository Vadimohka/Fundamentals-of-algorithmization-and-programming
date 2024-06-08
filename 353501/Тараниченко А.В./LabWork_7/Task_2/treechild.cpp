#include "treechild.h"

template<typename T, typename U>
TreeChild<T, U>::TreeChild()
{
    this->root = nullptr;
}

template<typename T, typename U>
int TreeChild<T, U>::leavesCount(Node<T, U> *node)
{
    if(node == nullptr) return 0;
    if(node && node->right == nullptr && node->left == nullptr) return 1;
    return (leavesCount(node->right) + leavesCount(node->left));
}

template<typename T, typename U>
int TreeChild<T, U>::leavesCount()
{
    return leavesCount(this->root);
}
