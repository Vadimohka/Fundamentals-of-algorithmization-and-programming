#include "ffcircle.h"

ffCircle::ffCircle()
{
    points.resize(1);
}

void ffCircle::findPerimetr()
{
    perimetr = 2 * PI * radius;
}

void ffCircle::findArea()
{
    area = PI * radius * radius;
}

void ffCircle::setPoints(QPoint msBeg, QPoint msNow)
{
    radius = abs(msNow.rx() - msBeg.rx());
    massCenter = msBeg;
    points[0] = massCenter;
}

void ffCircle::draw(QPainter *painter)
{
    painter->drawEllipse(points[0], radius, radius);
}

void ffCircle::scalingPoint(int ch)
{
    radius += ch;
}
