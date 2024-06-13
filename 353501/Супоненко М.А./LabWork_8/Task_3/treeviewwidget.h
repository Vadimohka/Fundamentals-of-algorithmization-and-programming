#ifndef TREEVIEWWIDGET_H
#define TREEVIEWWIDGET_H

#include <QWidget>
#include "redblacktree.h"

class TreeViewWidget : public QWidget {
    Q_OBJECT

public:
    explicit TreeViewWidget(QWidget *parent = nullptr);
    void setTree(RedBlackTree* t);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    RedBlackTree* tree;
    void drawNode(QPainter& painter, Node* node, int x, int y, int dx, int dy);
};

#endif // TREEVIEWWIDGET_H
