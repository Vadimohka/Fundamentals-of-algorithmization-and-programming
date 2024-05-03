#include "circle.h"
#include <QtMath>

Circle::Circle(QPointF point) : Figure(point)
{

}


void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));

    setArea(qAbs(M_PI * qPow(getHorizontalSide() / 2,2)));
    setPerimetr(qAbs(M_PI * getHorizontalSide()));

    painter->drawEllipse(boundingRect());

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
