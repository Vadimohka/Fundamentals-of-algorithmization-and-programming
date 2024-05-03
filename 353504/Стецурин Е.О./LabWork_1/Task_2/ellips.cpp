#include "ellips.h"
#include <QPainter>

Ellips::Ellips(qreal x,qreal y, qreal diametr1, qreal diametr2)
{
    group = new QGraphicsItemGroup(this);

    QGraphicsEllipseItem* ellipse = new QGraphicsEllipseItem(x,y,diametr1,diametr2);
    ellipse->setBrush(Qt::green);
    group->addToGroup(ellipse);

    QPolygon rhombus;
    rhombus << QPoint(2,0) << QPoint(0,2) << QPoint(-2,0)<< QPoint(0,-2);
    QGraphicsPolygonItem *rhombusItem = new QGraphicsPolygonItem(rhombus, this);
    rhombusItem->setBrush(Qt::red);

    group->addToGroup(rhombusItem);
    group->setFlag(QGraphicsItem::ItemIsMovable);
}

void EllipseDraw::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image("/home/hxppy/Pictures/sv.jpg");
    QBrush brush(image);

    painter->setPen(QPen(Qt::black, 3));
    painter->setBrush(brush);

    QRectF rect (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x(),endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y(),qAbs(endPoint().x()-startPoint().x()), qAbs(endPoint().y()-startPoint().y()));

    painter->drawEllipse(rect);

    int min =qAbs(endPoint().x()-startPoint().x()), max = qAbs(endPoint().y()-startPoint().y());

    emit coordinatesChanged(3.1415*min*max/4,3.1415*(3*(min/2+max/2)-sqrt((3*min/2+max/2)+(min/2+3*max/2))));

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
