#include "Romb.h"


Romb::Romb(){
    this->countofangles = 4;
}

Romb::Romb(int cx, int cy, int a, int b)
{
    this->countofangles = 0;
    this->SetCenter(cx, cy);
    angles.push_back(QPointF(this->center.x(), this->center.y() + b));
    angles.push_back(QPointF(this->center.x() + a, this->center.y()));
    angles.push_back(QPointF(this->center.x(), this->center.y() - b));
    angles.push_back(QPointF(this->center.x() - a, this->center.y()));
    this->countofangles = 4;

}

void Romb::SetWidth(int w)
{
    this->a = w;
    angles[1]=(QPointF(this->center.x() + a, this->center.y()));
    angles[3]=(QPointF(this->center.x() - a, this->center.y()));
}

void Romb::SetHeight(int h)
{
    this->b = h;
    angles[0]=(QPointF(this->center.x(), this->center.y() + b));
    angles[2]=(QPointF(this->center.x(), this->center.y() - b));
}


