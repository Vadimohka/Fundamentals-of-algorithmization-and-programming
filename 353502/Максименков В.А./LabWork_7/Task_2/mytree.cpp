#include "mytree.h"

void MyTree::deleteSubtreePerKey(int key)
{
    TreeNode* node = findNode(root, key);
    destroyTree(node, key);
}

