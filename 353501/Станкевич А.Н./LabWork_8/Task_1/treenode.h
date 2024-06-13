#ifndef TREENODE_H
#define TREENODE_H

#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>

class TreeNode : public QGraphicsEllipseItem
{
public:
    TreeNode(int key, const QString &value, QGraphicsItem *parent = nullptr);

    void setPosition(qreal x, qreal y);
    void setValue(const QString &value);

private:
    QGraphicsTextItem *text;
};

#endif // TREENODE_H
