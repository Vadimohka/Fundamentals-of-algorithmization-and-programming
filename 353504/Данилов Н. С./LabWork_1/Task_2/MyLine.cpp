#include "MyLine.h"

MyLine::MyLine(){}

MyLine::MyLine(int cx, int cy, int a, int b)
{
    this->center.setX(cx);
    this->center.setY(cy);
    this->a = a;
    this->b = b;
    countofangles = 1;
    angles.push_back(QPointF(cx, cy));
    S = 0;
    this->CountP();
}

void MyLine::Draw(QPainter *pr)
{
    pr->drawEllipse(center, 2,2);
    pr->drawPolyline(angles);
}

void MyLine::CountS()
{
    S = 0;
}



