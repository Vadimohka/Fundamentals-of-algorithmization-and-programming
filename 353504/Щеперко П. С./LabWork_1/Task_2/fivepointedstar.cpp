#include "fivepointedstar.h"

FivePointedStar::FivePointedStar() {}

void FivePointedStar::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPolygon star;
    painter->setRenderHint(QPainter::Antialiasing, true);
    star<< QPoint(0, -r1)
         << QPoint(r2*sin(qDegreesToRadians(36)),-r2*cos(qDegreesToRadians(36)))
         << QPoint(r1*sin(qDegreesToRadians(72)),-r1*cos(qDegreesToRadians(72)))
         << QPoint(r2*cos(qDegreesToRadians(18)),r2*sin(qDegreesToRadians(18)))
         << QPoint(r1*cos(qDegreesToRadians(54)),r1*sin(qDegreesToRadians(54)))
         << QPoint(0, r2)
         << QPoint(-r1*cos(qDegreesToRadians(54)),r1*sin(qDegreesToRadians(54)))
         << QPoint(-r2*cos(qDegreesToRadians(18)),r2*sin(qDegreesToRadians(18)))
         << QPoint(-r1*sin(qDegreesToRadians(72)),-r1*cos(qDegreesToRadians(72)))
         << QPoint(-r2*sin(qDegreesToRadians(36)),-r2*cos(qDegreesToRadians(36)));
    painter->drawPolygon(star);
}

float FivePointedStar::findArea()
{
    float s = this->getScale();
    return s*s*(M_PI*r1*r1+(M_PI*r2*r2-M_PI*r1*r1)/3);
}

float FivePointedStar::findPerimeter()
{
    float s = this->getScale();
    return r1*points+r2*points*s;
}

void FivePointedStar::setRs(float r1, float r2)
{
    this->r1 = r1;
    this->r2 = r2;
}

float FivePointedStar::getR1()
{
    return this->r1;
}

float FivePointedStar::getR2()
{
    return this->r2;
}

void FivePointedStar::setPoints(int p)
{
    this->points = p;
}

int FivePointedStar::getPoints()
{
    return this->points;
}
