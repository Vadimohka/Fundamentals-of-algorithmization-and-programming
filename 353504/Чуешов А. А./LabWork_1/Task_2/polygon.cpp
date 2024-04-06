#include "polygon.h"

polygon::polygon()
{

}
void polygon::setPoints(QMouseEvent *me)
{
    mouseNow=me->pos();
    points.push_back(mouseNow);
}
void polygon::draw(QPainter *painter,float scale)
{
    painter->setRenderHint(QPainter::Antialiasing, true);

    if(points.size())
    {
        int xp = points[0].x(), xm = points[0].x(), yp = points[0].y(), ym = points[0].y();
        for(auto &a : points)
        {
            xp = qMin(xp, a.x());
            yp = qMin(yp, a.y());
            xm = qMax(xm, a.x());
            ym = qMax(ym, a.y());
        }
        center = {(xp + xm) / 2, (yp + ym) / 2};
    }

    for(int i=0;i < points.size() - 1;++i)
    {
        QPointF x1 = center + (points[i] - center) * scale;
        QPointF x2 = center + (points[i + 1] - center) * scale;
        QLineF line(x1,  x2);
        painter->drawLine(line);
    }
}

float polygon::area()
{
    return 0;
}

float polygon::perimeter()
{
    return 0;
}
