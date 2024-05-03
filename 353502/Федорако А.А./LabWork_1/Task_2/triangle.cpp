#include "triangle.h"

Triangle::Triangle(QPointF point) : Figure(point)
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));


    QPolygonF polygon;

    setArea(qAbs(getHorizontalSide() * getVerticalSide()) / 2);

    setPerimetr(qAbs(getHorizontalSide() * (4 + 2 * qSqrt(5)) / 4));

    polygon << QPointF((getFirstPoint().x() + getSecondPoint().x()) / 2, getFirstPoint().y())
            << QPointF(getFirstPoint().x(), getSecondPoint().y())
            << QPointF(getSecondPoint().x(),getSecondPoint().y());

    painter->drawPolygon(polygon);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
