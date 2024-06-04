#ifndef GRAPHNODEITEM_H
#define GRAPHNODEITEM_H

#include <QGraphicsEllipseItem>
#include <QObject>

class GraphNodeItem : public QObject, public QGraphicsEllipseItem
{
    Q_OBJECT

public:
    GraphNodeItem(int value, QGraphicsItem *parent = nullptr);

signals:
    void nodeClicked(QGraphicsEllipseItem *node);
    void positionChanged();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

private:
    int m_value;
};

#endif // GRAPHNODEITEM_H
