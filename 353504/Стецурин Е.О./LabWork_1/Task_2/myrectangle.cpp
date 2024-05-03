#include "myrectangle.h"
#include <QPainter>

MyRectangle::MyRectangle(int x, int y, QGraphicsPolygonItem* parent): Figure(parent)
{
    QPolygonF rect;
    setBrush(Qt::green);

    rect << QPoint(-x/2, y/2)
       << QPoint(x/2, y/2)
       << QPoint(x/2, -y/2)
       << QPoint(-x/2, -y/2);
    setPolygon(rect);
    setFlag(QGraphicsItem::ItemIsMovable);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);
    rhombusItem->setFlag(QGraphicsItem::ItemIsMovable);
}

void RectDraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(QBrush(Qt::blue));

    QRectF rect (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),qAbs(endPoint().x()-startPoint().x()), qAbs(endPoint().y()-startPoint().y()));

    painter->drawRect(rect);

    int min =qAbs(endPoint().x()-startPoint().x()), max = qAbs(endPoint().y()-startPoint().y());

    emit coordinatesChanged(min*max,(min+max)*2);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}

