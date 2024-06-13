#ifndef MYBINTREE_H
#define MYBINTREE_H

#include "bintree.h"
#include <QString>
#include <qcontainerfwd.h>
#include <qtablewidget.h>
#include <qtreewidget.h>
#include <qframe.h>
#include <qnamespace.h>

class MyBinTree: public BinTree<QString> {
private:
    QTreeWidgetItem *generateForNode(TreeNode *node);
    long lenForNode(TreeNode *node);

public:

    MyBinTree();
    ~MyBinTree();

    void randomize();

    void fillEnties(QTreeWidget *entries);

    long findTotalLen();
};

#endif // MYBINTREE_H
