#ifndef TASKBST_H
#define TASKBST_H
#include "bst.h"

class TaskBST : public BST
{
public:
    Node* remove(Node* root, int key) override;
};

#endif // TASKBST_H
