#include "polygon.h"

Polygon::Polygon()
{

}
void Polygon::setPoints(QMouseEvent *me)
{
    mouseNow=me->pos();
    points.push_back(mouseNow);
}

void Polygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if(points.size())
    {
        /*int xp = points[0].x(), xm = points[0].x(), yp = points[0].y(), ym = points[0].y();
        for(auto &p : points)
        {
            xp = qMin(xp, p.x());
            yp = qMin(yp, p.y());
            xm = qMax(xm, p.x());
            ym = qMax(ym, p.y());
        }
        center = {(xp + xm) / 2, (yp + ym) / 2};*/
        for (const auto &p : points)
        {
            center += p;
        }
        center.setX(center.x() / points.size());
        center.setY(center.y() / points.size());
    }

    QPen *pen = new QPen();
    pen->setWidth(5);
    painter->setPen(*pen);
    painter->drawPoints(points);
}

float Polygon::area()
{
    return 0;
}

float Polygon::perimeter()
{
    return 0;
}
