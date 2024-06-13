#include "treenode.h"
#include "qfont.h"

TreeNode::TreeNode(int key, const QString &value, QGraphicsItem *parent)
    : QGraphicsEllipseItem(parent)
{
    setRect(-20, -20, 40, 40);

    setPen(QPen(Qt::black));
    setBrush(QBrush(Qt::green));

    text = new QGraphicsTextItem(QString::number(key) + ": " + value, this);

    QFont font = text->font();
    font.setPointSize(12);
    text->setFont(font);

    text->setPos(-text->boundingRect().width() / 2, -text->boundingRect().height() / 2);
}

void TreeNode::setPosition(qreal x, qreal y)
{
    setPos(x, y);
}
