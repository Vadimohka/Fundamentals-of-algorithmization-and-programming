#include "romb.h"

Romb::Romb(QPointF point) : Shape(point){}

void Romb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 4));

    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());
    qreal side = fmin(width, heigh);

    square = (width * heigh / 2);
    perimetr = side * 4;


    QPolygonF polygons;

    QPointF pt_1 = {fmin(GetStarterPoint().x() + width / 2, GetEndPoint().x() + width / 2), fmin(GetStarterPoint().y(), GetEndPoint().y())};
    QPointF pt_2 = {fmin(GetStarterPoint().x() + width, GetEndPoint().x() + width), fmin(GetStarterPoint().y() + heigh / 2, GetEndPoint().y() + heigh / 2)};
    QPointF pt_3 = {fmin(GetStarterPoint().x() + width / 2, GetEndPoint().x() + width / 2), fmin(GetStarterPoint().y() + heigh, GetEndPoint().y() + heigh)};
    QPointF pt_4 = {fmin(GetStarterPoint().x(), GetEndPoint().x()), fmin(GetStarterPoint().y() + heigh / 2, GetEndPoint().y() + heigh / 2)};

    polygons << pt_1 << pt_2 << pt_3 << pt_4;

    painter->drawPolygon(polygons);
}

qreal Romb::GetSquare()
{
    return square;
}

qreal Romb::GetPerimetr()
{
    return perimetr;
}

QPointF Romb::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}
