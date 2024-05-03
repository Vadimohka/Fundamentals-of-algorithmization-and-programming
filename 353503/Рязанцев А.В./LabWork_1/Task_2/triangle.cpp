#include "triangle.h"

Triangle::Triangle(QPointF point) : Shape(point){
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 4));

    qreal width = qAbs(GetEndPoint().x() - GetStarterPoint().x());
    qreal heigh = qAbs(GetEndPoint().y() - GetStarterPoint().y());
    qreal side = qSqrt(((width / 2) * (width / 2)) + (heigh * heigh));

    square = width * heigh / 2;
    perimetr = width + side * 2;

    QPolygonF polygons;

    QPointF pt_1 = {GetStarterPoint().x(), GetStarterPoint().y()};
    QPointF pt_2 = {GetEndPoint().x(), GetStarterPoint().y()};
    QPointF pt_3 = {fmin(GetStarterPoint().x() + width / 2, GetEndPoint().x() + width / 2),
                    GetEndPoint().y()};

    polygons << pt_1 << pt_2 << pt_3;

    painter->drawPolygon(polygons);
}

qreal Triangle::GetSquare()
{
    return square;
}

qreal Triangle::GetPerimetr()
{
    return perimetr;
}

QPointF Triangle::GetCenter()
{
    center = {boundingRect().center().x(), boundingRect().center().y()};
    return center;
}
