#include "circle.h"


Circle::Circle(QPointF point, QObject *parent) :
    Figure(point, parent)
{
    Q_UNUSED(point)
}



void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(myColor);

    points << QPointF(startPoint().x(), startPoint().y());

    painter->drawEllipse(points[0].x()-a, points[0].y()-a, 2*a, 2*a);

    X = startPoint().x();
    Y = startPoint().y();


    S = 4*a*a*M_PI;
    P = 4*M_PI*a;

    Q_UNUSED(option);
    Q_UNUSED(widget);

    m_shape = QPainterPath();
    m_shape.addEllipse(points[0].x()-a, points[0].y()-a, 2*a, 2*a);
}
