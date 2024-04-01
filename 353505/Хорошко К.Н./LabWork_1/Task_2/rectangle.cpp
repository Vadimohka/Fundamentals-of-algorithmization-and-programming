#include "rectangle.h"

Rectangle::Rectangle(QPointF point, QObject *parent) : Figure(point, parent)
{
    Q_UNUSED(point);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(myColor);

    points << QPointF(startPoint().x()-2*a, startPoint().y()+a) << QPointF(startPoint().x() + 2*a, startPoint().y()+a)
           << QPointF(startPoint().x() + 2*a, startPoint().y() -a) << QPointF(startPoint().x() - 2*a, startPoint().y() - a);

    QPolygonF polygon(points);

    painter->drawPolygon(polygon);


    X = startPoint().x();
    Y = startPoint().y();
    P = 12*a;
    S = 8*a*a;

    Q_UNUSED(option);
    Q_UNUSED(widget);
    m_shape = QPainterPath();
    m_shape.addPolygon(polygon);
    points.clear();
}
