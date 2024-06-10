#include "hexagon.h"

Hexagon::Hexagon(): Shape()
{}

void Hexagon::setPoints(QVector<QPointF>points)
{
    temp = points;
    a = (QLineF(points.at(0),points.at(1))).length();
    Topleft = QPointF(temp.at(0).x() - a,temp.at(0).y() - a);
    rect = QRectF(Topleft.x(),Topleft.y(),2*a,2*a);
    center = points.at(0);
}

long double Hexagon::square()
{
    return (3 * qSqrt(3) * a * a) / 2;
}

long double Hexagon::perimetr()
{
    return 6 * a;
}
qreal Hexagon::getSpecificParam_1()
{
    return a;
}

void Hexagon::setSpecificParam_1(qreal t)
{
    rect = QRectF(rect.center().x() - t,rect.center().y() - t,2*t,2*t);
    a = t;
}
QRectF Hexagon::boundingRect() const
{
    return QRectF(temp.at(0).x() - a,temp.at(0).y() - a, 2*a,2*a);
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    double angle =  2 * M_PI / 6;
    QPolygon polygon;
    QPointF x = QPointF(temp[0].x(),temp[0].y());

    for(int i = 0;i < 6;i++)
    {
        polygon << QPoint(x.x() + a * cos(i * angle), x.y() + a * sin(i * angle));
    }

    QPen pen = QPen(this->getColor());
    pen.setCosmetic(true);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setBrush(this->getBrush());
    painter->drawPolygon(polygon);
}
