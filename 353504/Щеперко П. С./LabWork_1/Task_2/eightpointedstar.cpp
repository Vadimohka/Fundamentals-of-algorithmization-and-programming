#include "eightpointedstar.h"

EightPointedStar::EightPointedStar() {}

void EightPointedStar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygon star;
    painter->setRenderHint(QPainter::Antialiasing, true);
    star << QPoint(0, -r1)
         << QPoint(r2*sin(qDegreesToRadians(22.5)),-r2*cos(qDegreesToRadians(22.5)))
         << QPoint(r1*sin(qDegreesToRadians(45)),-r1*cos(qDegreesToRadians(45)))
         << QPoint(r2*sin(qDegreesToRadians(67.5)),-r2*cos(qDegreesToRadians(67.5)))
         << QPoint(r1, 0)
         << QPoint(r2*sin(qDegreesToRadians(67.5)),r2*cos(qDegreesToRadians(67.5)))
         << QPoint(r1*sin(qDegreesToRadians(45)),r1*cos(qDegreesToRadians(45)))
         << QPoint(r2*sin(qDegreesToRadians(22.5)),r2*cos(qDegreesToRadians(22.5)))
         << QPoint(0, r1)
         << QPoint(-r2*sin(qDegreesToRadians(22.5)),r2*cos(qDegreesToRadians(22.5)))
         << QPoint(-r1*sin(qDegreesToRadians(45)),r1*cos(qDegreesToRadians(45)))
         << QPoint(-r2*sin(qDegreesToRadians(67.5)),r2*cos(qDegreesToRadians(67.5)))
         << QPoint(-r1, 0)
         << QPoint(-r2*sin(qDegreesToRadians(67.5)),-r2*cos(qDegreesToRadians(67.5)))
         << QPoint(-r1*sin(qDegreesToRadians(45)),-r1*cos(qDegreesToRadians(45)))
         << QPoint(-r2*sin(qDegreesToRadians(22.5)),-r2*cos(qDegreesToRadians(22.5)));
    painter->drawPolygon(star);
}

float EightPointedStar::findArea()
{
    float s = this->getScale();
    return s*s*(M_PI*r1*r1+(M_PI*r2*r2-M_PI*r1*r1)/8);
}

float EightPointedStar::findPerimeter()
{
    float s = this->getScale();
    return r1*points+r2*points*s;
}

void EightPointedStar::setRs(float r1, float r2)
{
    this->r1 = r1;
    this->r2 = r2;
}

float EightPointedStar::getR1()
{
    return this->r1;
}

float EightPointedStar::getR2()
{
    return this->r2;
}

void EightPointedStar::setPoints(int p)
{
    this->points = p;
}

int EightPointedStar::getPoints()
{
    return this->points;
}
