#include "circle.h"


Circle::Circle(QPointF p, QPointF r)
{
    xrad= std::max(r.x(), r.y());
    yrad = yrad;
    center = p;
}

Circle::Circle()
{

}

void Circle::setSize(QPointF r)
{
    xrad = std::max(r.x(), r.y());
    yrad = xrad;
}

double Circle::getS()
{
    s = M_PI * xrad * xrad / 4;
    return s;
}

double Circle::getP()
{
    p = fabs(2 * M_PI * xrad / 2);
    return p;
}
