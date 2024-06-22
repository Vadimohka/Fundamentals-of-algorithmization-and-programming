#include "AVL_Tree.h"

AVL_Tree::AVL_Tree::AVL_Tree(QVector<QPair<int, QString> > initial)
{
    for (auto elem : initial){
        this->insert(elem.first, elem.second);
    }
    //balance();
}

void AVL_Tree::AVL_Tree::insert(int key, QString info)
{
    if (find(key) == "")
        insertInTree(key, info, root);
}

void AVL_Tree::AVL_Tree::erase(int key)
{
    Node* a = nullptr;
    eraseFromTree(key, root, a, 1);
}

void AVL_Tree::AVL_Tree::balance()
{
    //while(!isBalanced(root))
    balanceTreeHelper(root);
    QCoreApplication::processEvents();
    QThread::msleep(100);
}
