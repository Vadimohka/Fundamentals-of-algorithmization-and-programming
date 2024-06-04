#include "figure.h"

figure::figure() {}

void figure::findPerimetr()
{
    float x1 = points[points.size() - 1].rx(), y1 = points[points.size() - 1].ry();
    float x2 = points[0].rx(), y2 = points[0].ry();

    perimetr = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));

    for (int i = 0; i < points.size() - 1; i++)
    {
        float x1 = points[i].rx(), y1 = points[i].ry();
        float x2 = points[i+1].rx(), y2 = points[i+1].ry();

        perimetr += sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
}

void figure::findArea()
{
    area = 0;

    for (int i = 0; i < points.size(); i++)
    {
        area += (points[i].rx() * points[(i+1)%(points.size())].ry()) - (points[i].ry() * points[(i+1)%(points.size())].rx());
    }

    area = fabs(area);
    area = area / 2.0;
}

void figure::setPoints(QPoint msBeg, QPoint msNow)
{
    Q_UNUSED(msBeg);
    Q_UNUSED(msNow);
}

void figure::draw(QPainter *painter)
{
    QPolygonF plg;

    for(int i = 0; i < points.size(); i++)
    {
        plg << points[i];
    }

    painter->drawPolygon(plg);
}

void figure::rotatePoint(QPointF point, float angle)
{
    float px = point.rx();
    float py = point.ry();

    for(int i = 0; i < points.size(); i++)
    {
        points[i].rx() = (points[i].rx() - px)*cos(angle * acos(-1) / 180.0) - (points[i].ry() - py)*sin(angle * acos(-1) / 180.0) + px;
        points[i].ry() = (points[i].ry() - py)*cos(angle * acos(-1) / 180.0) + (points[i].rx() - px)*sin(angle * acos(-1) / 180.0) + py;
    }

    massCenter.rx() = (massCenter.rx() - px)*cos(angle * acos(-1) / 180.0) - (massCenter.ry() - py)*sin(angle * acos(-1) / 180.0) + px;
    massCenter.ry() = (massCenter.ry() - py)*cos(angle * acos(-1) / 180.0) + (massCenter.rx() - px)*sin(angle * acos(-1) / 180.0) + py;
}

void figure::move(QPoint delta)
{
    for(int i = 0; i < points.size(); i++)
    {
        points[i] += delta;
    }

    massCenter += delta;
}

void figure::scalingPoint(int ch)
{
    for(int i = 0; i < points.size(); i++)
    {
        float otnosh = abs(points[i].rx() - massCenter.rx()) / abs(points[i].ry() - massCenter.ry());

        float ox = otnosh;
        float oy = 1;

        if(otnosh > 1)
        {
            otnosh = abs(points[i].ry() - massCenter.ry()) / abs(points[i].rx() - massCenter.rx());
            ox = 1;
            oy = otnosh;
        }

        if(points[i].rx() < massCenter.rx())
        {

            points[i].rx() -= ch * ox;
        }
        else
        {
            points[i].rx() += ch * ox;
        }

        if(points[i].ry() < massCenter.ry())
        {
            points[i].ry() -= ch * oy;
        }
        else
        {
            points[i].ry() += ch * oy;
        }
    }
}
