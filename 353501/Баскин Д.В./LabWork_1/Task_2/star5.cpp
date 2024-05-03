#include "star5.h"

Star5::Star5()
{

}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    QPointF points[11];

    for (int i = 0; i < 5; i++)
    {
           QPointF p_out, p_in;
           p_out = {
                   0 - radiusA * sin(2 * M_PI / 5 * i),
                   0 - radiusA * cos(2 * M_PI / 5 * i)
           };

           p_in = {
                   0 - radiusB * sin(2 * M_PI / 5 * i + M_PI / 5),
                   0 - radiusB * cos(2 * M_PI / 5 * i + M_PI / 5)
           };
           points[i * 2] = p_out;
           points[i * 2 + 1] = p_in;
    }

    points[10].rx() = points[0].rx();
    points[10].ry() = points[0].ry();

    for (int i = 0; i < 10; ++i)
    {
        painter->drawLine(points[i].rx(),points[i].ry(), points[i + 1].rx(),points[i + 1].ry());
    }
}

float Star5::area()
{
    return this->getScale() * this->getScale() * (M_PI * radiusA * radiusA + (M_PI * radiusB * radiusB - M_PI * radiusA * radiusA) / 3);
}

float Star5::perimeter()
{
    return (radiusA + radiusB) * 5 * this->getScale();
}

void Star5::setRadiusA(int value)
{
    this->radiusA = value;
    update();
}

void Star5::setRadiusB(int value)
{
    this->radiusB = value;
    update();
}

float Star5::getRadiusA()
{
    return this->radiusA;
}

float Star5::getRadiusB()
{
    return this->radiusB;
}
