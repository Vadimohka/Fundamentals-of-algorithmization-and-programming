#include "romb.h"

Romb::Romb(QPointF point) : Figure(point)
{

}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));

    QPolygonF romb;

    setArea(qAbs(getHorizontalSide() * getVerticalSide() / 2));
    setPerimetr(qAbs(4 * qSqrt(qPow(getHorizontalSide() / 2, 2) + qPow(getVerticalSide() / 2, 2))));
    romb << QPointF(getFirstPoint().x(), (getFirstPoint().y()+getSecondPoint().y())/2)
            << QPointF((getFirstPoint().x() + getSecondPoint().x())/2, getSecondPoint().y())
            << QPointF(getSecondPoint().x(), (getFirstPoint().y()+getSecondPoint().y())/2)
            << QPointF((getFirstPoint().x() + getSecondPoint().x())/2, getFirstPoint().y());

    painter->drawPolygon(romb);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
