#include "star6.h"

Star6::Star6()
{

}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPointF points[13];

    for (int i = 0; i < 6; i++)
    {
           QPointF p_out, p_in;
           p_out = {
                   0 - radiusA * sin(2 * M_PI / 6 * i),
                   0 - radiusA * cos(2 * M_PI / 6 * i)
           };

           p_in = {
                   0 - radiusB * sin(2 * M_PI / 6 * i + M_PI / 6),
                   0 - radiusB * cos(2 * M_PI / 6 * i + M_PI / 6)
           };
           points[i * 2] = p_out;
           points[i * 2 + 1] = p_in;
    }

    points[12].rx() = points[0].rx();
    points[12].ry() = points[0].ry();

    for (int i = 0; i < 12; ++i)
    {
        painter->drawLine(points[i].rx(),points[i].ry(), points[i + 1].rx(),points[i + 1].ry());
    }
}

float Star6::area()
{
    return this->getScale() * this->getScale() * (M_PI * radiusA * radiusA + (M_PI * radiusB * radiusB - M_PI * radiusA * radiusA) / 5);
}

float Star6::perimeter()
{
    return (radiusA + radiusB) * 6 * this->getScale();
}

void Star6::setRadiusA(int value)
{
    this->radiusA = value;
    update();
}

void Star6::setRadiusB(int value)
{
    this->radiusB = value;
    update();
}

float Star6::getRadiusA()
{
    return this->radiusA;
}

float Star6::getRadiusB()
{
    return this->radiusB;
}
