#include "hexagon.h"


Hexagon::Hexagon(QPointF point, QObject *parent) : Figure(point, parent)
{
    Q_UNUSED(point);
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(myColor);

    qreal angle = qDegreesToRadians(60);

    points << QPointF(startPoint().x() - a, startPoint().y()) << QPointF(startPoint().x() - a*cos(angle), startPoint().y()+a*sin(angle))
           << QPointF(startPoint().x() +a*cos(angle), startPoint().y() + a*sin(angle)) << QPointF(startPoint().x() + a, startPoint().y())
           << QPointF(startPoint().x() +a*cos(angle), startPoint().y() - a*sin(angle)) << QPointF(startPoint().x() - a*cos(angle), startPoint().y() - a*sin(angle));

    QPolygonF polygon(points);

    painter->drawPolygon(polygon);


    X = startPoint().x();
    Y = startPoint().y();
    P = 6 * a;
    S = 3/2*sqrt(3)*a*a;

    Q_UNUSED(option);
    Q_UNUSED(widget);

    m_shape = QPainterPath();
    m_shape.addPolygon(polygon);

    points.clear();
}
