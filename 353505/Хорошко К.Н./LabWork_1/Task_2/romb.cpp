#include "romb.h"


Romb::Romb(QPointF point, QObject *parent) : Figure(point, parent)
{
    Q_UNUSED(point);
}

Romb::~Romb(){

}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(Qt::black);
    painter->setBrush(myColor);

    points << QPointF(startPoint().x(), startPoint().y()+a/2) << QPointF(startPoint().x() + a, startPoint().y())
           << QPointF(startPoint().x(), startPoint().y() - a/2) << QPointF(startPoint().x() - a, startPoint().y());

    QPolygonF polygon(points);

    painter->drawPolygon(polygon);

    X = startPoint().x();
    Y = startPoint().y();

    S = 4*a*a;
    P = 4 * sqrt(5)*a;

    Q_UNUSED(option);
    Q_UNUSED(widget);
    m_shape = QPainterPath();
    m_shape.addPolygon(polygon);
        points.clear();
}
