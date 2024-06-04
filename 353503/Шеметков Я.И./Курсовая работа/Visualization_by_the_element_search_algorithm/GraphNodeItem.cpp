#include "GraphNodeItem.h"
#include <QGraphicsSceneMouseEvent>

GraphNodeItem::GraphNodeItem(int value, QGraphicsItem *parent)
    : QGraphicsEllipseItem(parent), m_value(value)
{
    setFlag(QGraphicsItem::ItemIsMovable);
    setFlag(QGraphicsItem::ItemSendsGeometryChanges);
    setData(0, value);
}

void GraphNodeItem::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    emit nodeClicked(this);
    QGraphicsEllipseItem::mousePressEvent(event);
}

void GraphNodeItem::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsEllipseItem::mouseMoveEvent(event);
    emit positionChanged();
}
