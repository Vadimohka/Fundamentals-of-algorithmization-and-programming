#include "triangle.h"

Triangle::Triangle(QPointF point, QObject *parent) : Figure(point, parent)
{
    Q_UNUSED(point);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(myColor);

    points << QPointF(startPoint().x(), startPoint().y() + 1.5*a/sqrt(3)) << QPointF(startPoint().x() + 1.5*a/2, startPoint().y() - 1.5*a*sqrt(3)/6)
           << QPointF(startPoint().x() - 1.5*a/2, startPoint().y() - 1.5*a*sqrt(3)/6);

    QPolygonF polygon(points);

    painter->drawPolygon(polygon);


    X = startPoint().x();
    Y = startPoint().y();

    P = 6*a;
    S = a*a/4*sqrt(3);

    Q_UNUSED(option);
    Q_UNUSED(widget);
    m_shape = QPainterPath();
    m_shape.addPolygon(polygon);
        points.clear();
}
