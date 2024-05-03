#include "star8.h"

Star8::Star8()
{

}

void Star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPointF points[17];

    for (int i = 0; i < 8; i++)
    {
           QPointF p_out, p_in;
           p_out = {
                   0 - radiusA * sin(2 * M_PI / 8 * i),
                   0 - radiusA * cos(2 * M_PI / 8 * i)
           };

           p_in = {
                   0 - radiusB * sin(2 * M_PI / 8 * i + M_PI / 8),
                   0 - radiusB * cos(2 * M_PI / 8 * i + M_PI / 8)
           };
           points[i * 2] = p_out;
           points[i * 2 + 1] = p_in;
    }

    points[16].rx() = points[0].rx();
    points[16].ry() = points[0].ry();

    for (int i = 0; i < 16; ++i)
    {
        painter->drawLine(points[i].rx(),points[i].ry(), points[i + 1].rx(),points[i + 1].ry());
    }
}

float Star8::area()
{
    return this->getScale() * this->getScale() * (M_PI * radiusA * radiusA + (M_PI * radiusB * radiusB - M_PI * radiusA * radiusA) / 4);
}

float Star8::perimeter()
{
    return (radiusA + radiusB) * 8 * this->getScale();
}

void Star8::setRadiusA(int value)
{
    this->radiusA = value;
    update();
}

void Star8::setRadiusB(int value)
{
    this->radiusB = value;
    update();
}

float Star8::getRadiusA()
{
    return this->radiusA;
}

float Star8::getRadiusB()
{
    return this->radiusB;
}
