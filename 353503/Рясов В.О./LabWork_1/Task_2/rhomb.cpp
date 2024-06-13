#include "rhomb.h"

#include <QPainter>

Rhomb::Rhomb(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 2));

    QPolygonF rhpol;

    QPointF center = (startPoint() + endPoint()) / 2;
    qreal halfDiagonal = (startPoint() - endPoint()).manhattanLength() / 2;

    rhpol << QPointF(center.x(), center.y() - halfDiagonal)
          << QPointF(center.x() + halfDiagonal, center.y())
          << QPointF(center.x(), center.y() + halfDiagonal)
          << QPointF(center.x() - halfDiagonal, center.y());

    painter->drawPolygon(rhpol);

    Q_UNUSED(widget)
    Q_UNUSED(option)
}
