#ifndef VISUALBST_H
#define VISUALBST_H

#include "Searchtree.h"
#include <QString>
#include <QTreeWidget>



class VisualBST : public SearchTree<QString> {
private:
    void storeBSTNodes(QVector<TreeNode*>& nodes, TreeNode* root);
    TreeNode* buildTree(QVector<TreeNode*>& nodes, int start, int end);

public:
    VisualBST();
    ~VisualBST();

    void randomize();
    void fillEntries(QTreeWidget* tree);
    long findTotalLen();
    void balanceTree();

    QTreeWidgetItem* generateForNode(TreeNode* node);
    long lenForNode(TreeNode* node);
};

#endif // SOLVER_H