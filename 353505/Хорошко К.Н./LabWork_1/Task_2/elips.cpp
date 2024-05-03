#include "elips.h"

Elips::Elips(QPointF point, QObject *parent) :
    Figure(point, parent)
{
    Q_UNUSED(point)
}



void Elips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(myColor);

    points << QPointF(startPoint().x(), startPoint().y());

    painter->drawEllipse(points[0].x()-a, points[0].y()-a/2, 2*a, a);


    X = startPoint().x();
    Y = startPoint().y();

    S = M_PI * 2*a * a;
    P = M_PI*(3*3*a-a*sqrt(35));

    Q_UNUSED(option);
    Q_UNUSED(widget);

    m_shape = QPainterPath();
    m_shape.addEllipse(points[0].x()-a, points[0].y()-a/2, 2*a, a);
}
