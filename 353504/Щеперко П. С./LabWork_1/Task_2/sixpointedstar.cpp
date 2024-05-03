#include "sixpointedstar.h"

SixPointedStar::SixPointedStar() {}

void SixPointedStar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygon star;
    painter->setRenderHint(QPainter::Antialiasing, true);
    star << QPoint(0, -r1)
         << QPoint(r2*sin(qDegreesToRadians(30)),-r2*cos(qDegreesToRadians(30)))
         << QPoint(r1*sin(qDegreesToRadians(60)),-r1*cos(qDegreesToRadians(60)))
         << QPoint(r2, 0)
         << QPoint(r1*sin(qDegreesToRadians(60)),r1*cos(qDegreesToRadians(60)))
         << QPoint(r2*sin(qDegreesToRadians(30)),r2*cos(qDegreesToRadians(30)))
         << QPoint(0, r1)
         << QPoint(-r2*sin(qDegreesToRadians(30)),r2*cos(qDegreesToRadians(30)))
         << QPoint(-r1*sin(qDegreesToRadians(60)),r1*cos(qDegreesToRadians(60)))
         << QPoint(-r2, 0)
         << QPoint(-r1*sin(qDegreesToRadians(60)),-r1*cos(qDegreesToRadians(60)))
         << QPoint(-r2*sin(qDegreesToRadians(30)),-r2*cos(qDegreesToRadians(30)));
    painter->drawPolygon(star);
}

float SixPointedStar::findArea()
{
    float s = this->getScale();
    return s*s*(M_PI*r1*r1+(M_PI*r2*r2-M_PI*r1*r1)/5);
}

float SixPointedStar::findPerimeter()
{
    float s = this->getScale();
    return r1*points+r2*points*s;
}

void SixPointedStar::setRs(float r1, float r2)
{
    this->r1 = r1;
    this->r2 = r2;
}

float SixPointedStar::getR1()
{
    return this->r1;
}

float SixPointedStar::getR2()
{
    return this->r2;
}

void SixPointedStar::setPoints(int p)
{
    this->points = p;
}

int SixPointedStar::getPoints()
{
    return this->points;
}
