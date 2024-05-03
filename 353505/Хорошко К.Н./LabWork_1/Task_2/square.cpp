#include "square.h"

Square::Square(QPointF point, QObject *parent) : Figure(point, parent)
{
    Q_UNUSED(point)
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(myColor);

    points << QPointF(startPoint().x()+a, startPoint().y()+a) << QPointF(startPoint().x() - a, startPoint().y()+a)
           << QPointF(startPoint().x()-a, startPoint().y() - a) << QPointF(startPoint().x() + a, startPoint().y() - a);

    QPolygonF polygon(points);

    painter->drawPolygon(polygon);

    X = startPoint().x();
    Y = startPoint().y();
    P = 8*a;
    S = 4*a*a;

    Q_UNUSED(option)
    Q_UNUSED(widget)
    m_shape = QPainterPath();
    m_shape.addPolygon(polygon);
        points.clear();
}
