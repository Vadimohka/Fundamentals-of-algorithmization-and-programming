#include "Circle.h"

Circle::Circle(){}

Circle::Circle(int cx, int cy, int a, int b)
{
    this->center.setX(cx);
    this->center.setY(cy);
    this->a = a;
    this->b = b;
    countofangles = 0;
}

void Circle::Draw(QPainter *pr)
{
    pr->drawEllipse(center, 2,2);
    pr->translate(center.x(), center.y());
    double D = a;
    pr->drawEllipse(-D/2, -D/2, D, D);
}

void Circle::CountS()
{
    S = fabs(3.14*a*a);
}

void Circle::CountP()
{
    P = fabs(2*3.14*a);
}

void Circle::Resize(bool big)
{
    this->a *= big ? 1.01 : 0.99;
    this->b *= big ? 1.01 : 0.99;
}
