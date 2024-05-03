#include "hexagon.h"

Hexagon::Hexagon(QPointF point) : Shape(point){}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 4));

    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());

    QPolygonF polygons;

    QPointF pt_1 = {fmin(GetStarterPoint().x() + width * 0.25, GetEndPoint().x() + width * 0.75), GetStarterPoint().y()};
    QPointF pt_2 = {fmin(GetStarterPoint().x() + width * 0.75, GetEndPoint().x() + width * 0.25), GetStarterPoint().y()};
    QPointF pt_3 = {GetEndPoint().x(), fmin(GetStarterPoint().y() + heigh / 2, GetEndPoint().y() + heigh / 2)};
    QPointF pt_4 = {fmin(GetStarterPoint().x() + width * 0.75, GetEndPoint().x() + width * 0.25), GetEndPoint().y()};
    QPointF pt_5 = {fmin(GetStarterPoint().x() + width * 0.25, GetEndPoint().x() + width * 0.75), GetEndPoint().y()};
    QPointF pt_6 = {GetStarterPoint().x(), fmin(GetStarterPoint().y() + heigh / 2, GetEndPoint().y() + heigh / 2)};

    qreal side = qAbs(pt_2.x() - pt_1.x());
    square =( width + side) * heigh / 2;
    perimetr = side * 6;

    polygons << pt_1 << pt_2 << pt_3 << pt_4 << pt_5 << pt_6;

    painter->drawPolygon(polygons);
}

qreal Hexagon::GetSquare()
{
    return square;
}

qreal Hexagon::GetPerimetr()
{
    return perimetr;
}

QPointF Hexagon::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}
