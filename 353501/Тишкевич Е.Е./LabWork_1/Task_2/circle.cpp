#include "circle.h"

Circle::Circle(){}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->drawEllipse(-radA/2*scale,-radB/2*scale,radA*scale,radB*scale);
    painter->setPen(QPen(Qt::red, 3));
    painter->drawPoint(x,y);
    painter->setPen(QPen(Qt::darkGreen, 3));
    painter->drawPoint(0,0);
    painter->setPen(Qt::black);
}

float Circle::perim()
{
    return 4*this->getScale()*((M_PI*radA*radB+radA-radB)/(radA+radB));
}


float Circle::area()
{
    return this->getScale() * this->getScale() * radA * radB * M_PI;
}

float Circle::getRadF()
{
    return radA;
}

float Circle::getRadS()
{
    return radB;
}

void Circle::setRadF(float num)
{
    radA = num;
}

void Circle::setRadS(float num)
{
    radB = num;
}

