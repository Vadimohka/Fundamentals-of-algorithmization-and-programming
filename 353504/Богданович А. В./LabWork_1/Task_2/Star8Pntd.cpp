#include "Star8Pntd.h"

Star8Pntd::Star8Pntd()
{

}

void Star8Pntd::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
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

float Star8Pntd::findArea()
{
    float s = this->getScale();
    return s*s*(M_PI*r1*r1+(M_PI*r2*r2-M_PI*r1*r1)/8);
}

float Star8Pntd::findPerimeter()
{
    float s = this->getScale();
    return r1*points+r2*points*s;
}

void Star8Pntd::setRs(float r1, float r2)
{
    this->r1 = r1;
    this->r2 = r2;
}

float Star8Pntd::getR1()
{
    return this->r1;
}

float Star8Pntd::getR2()
{
    return this->r2;
}

void Star8Pntd::setPoints(int p)
{
    this->points = p;
}

int Star8Pntd::getPoints()
{
    return this->points;
}
