#include "hexagon.h"

Hexagon::Hexagon(QPointF point) : Figure(point)
{
    Q_UNUSED(point)
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    painter->setPen(QPen(Qt::black, 3));

    QPolygonF polygon;

    setArea(qAbs(getHorizontalSide() * getVerticalSide() * 2 / 3));
    setPerimetr(4 * qAbs(qSqrt(qPow(getVerticalSide(),2) + qPow(getHorizontalSide(),2))) + qAbs(getHorizontalSide() / 3 * 2));

    polygon << QPointF(getFirstPoint().x(), getFirstPoint().y() + getVerticalSide() / 2)
            << QPointF(getFirstPoint().x() + getHorizontalSide() / 3, getFirstPoint().y())
            << QPointF(getFirstPoint().x() + getHorizontalSide() * 2 / 3, getFirstPoint().y())
            << QPointF(getFirstPoint().x() + getHorizontalSide(), getFirstPoint().y() + getVerticalSide()/ 2)
            << QPointF(getFirstPoint().x() + getHorizontalSide() * 2 / 3, getSecondPoint().y())
            << QPointF(getFirstPoint().x() + getHorizontalSide() / 3, getSecondPoint().y());

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
