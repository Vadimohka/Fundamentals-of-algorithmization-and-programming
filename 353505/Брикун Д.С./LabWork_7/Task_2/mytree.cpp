#include "mytree.h"

QVector<int> MyTree::nodesPerLevel() {
    QVector<int> vec(1);
    if (root != nullptr) {
        nodesPerLevel(root, vec, 1);
    }
    return vec;
}

void MyTree::nodesPerLevel(TreeNode* node, QVector<int> & vec, int lev){
    if (node != nullptr){
        nodesPerLevel(node->left, vec, lev + 1);
        nodesPerLevel(node->right, vec, lev + 1);
        if (vec.size() < lev) vec.resize(lev);
        ++vec[lev - 1];
    }
}
