#include "polygon.h"

Polygon::Polygon(): Shape()
{}

void Polygon::setPoints(QVector<QPointF> point)
{
    p += point;
}

QRectF Polygon::boundingRect() const
{
    return polygon.boundingRect();
}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPolygon pol;
    QGraphicsItemGroup g;

    painter->setPen(this->getColor());

    for(int i = 0; i < p.size() - 1; i++)
    {
        painter->setPen(this->getColor());
        //painter->drawEllipse(QRcetF(p[i].x()-10,p[i].y()-10,p[i].x()-10,p[i].y()-10);
    }
}
