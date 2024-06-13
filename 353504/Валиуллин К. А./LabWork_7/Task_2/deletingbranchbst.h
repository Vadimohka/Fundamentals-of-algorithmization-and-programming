#ifndef DELETINGBRANCHBST_H
#define DELETINGBRANCHBST_H

#include "bst.h"

class deletingBranchBST : public BST {
public:
    void removeSubtree(int key);

private:
    void deleteSubtree(BSTNode* node);
};

#endif // DELETINGBRANCHBST_H
