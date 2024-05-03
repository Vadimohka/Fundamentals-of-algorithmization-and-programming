#include "rectangle.h"

Rectangle::Rectangle(QPointF point) : Figure(point)
{
    Q_UNUSED(point)
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));

    setArea(qAbs(getHorizontalSide() * getVerticalSide()));
    setPerimetr(qAbs(2 * (qAbs(getHorizontalSide()) + qAbs(getVerticalSide()))));


    painter->drawRect(boundingRect());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
