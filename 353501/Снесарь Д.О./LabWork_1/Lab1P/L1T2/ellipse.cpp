#include "ellipse.h"

Ellipse::Ellipse(QPointF centr, QPointF size)
{
    xrad = size.x();
    yrad = size.y();
    center = centr;
    rotAngle = 0;

}
Ellipse::Ellipse()
{

}

void Ellipse::draw(QPainter *pntr)
{

    QTransform originalTransform = pntr->transform();
   // pntr->drawEllipse(center, 3, 3);
    pntr->translate(center.x(), center.y());
    pntr->rotate(rotAngle);
    pntr->drawEllipse(-xrad/2,  -yrad/2, xrad, yrad);
    pntr->setTransform(originalTransform);

}

void Ellipse::setSize(QPointF nPoint)
{
    xrad = nPoint.x();
    yrad = nPoint.y();
}


void Ellipse::upScale()
{
    xrad *= 1.01;
    yrad *= 1.01;
}

void Ellipse::downScale()
{
    xrad *= 0.99;
    yrad *= 0.99;
}

void Ellipse::rotateL()
{
    rotAngle -= 2;
}

void Ellipse::rotateR()
{
    rotAngle += 2;
}

double Ellipse::getS()
{
    s = fabs(M_PI * xrad / 2 * yrad / 2);
    return s;
}

double Ellipse::getP()
{
    p = 2 * M_PI *sqrt((xrad * xrad + yrad * yrad)/8);
    return p;
}

int Ellipse::getId()
{
    return 2;
}

QPointF Ellipse::getRadSize()
{
    return QPointF(xrad, yrad);
}


