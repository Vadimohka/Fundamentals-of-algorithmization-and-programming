#include "Shestiuh.h"


Shestiuh::Shestiuh(){
    this->countofangles = 6;
}

Shestiuh::Shestiuh(int cx, int cy, int a, int b)
{
    this->countofangles = 0;
    this->SetCenter(cx, cy);
    angles.push_back(QPointF(this->center.x() - a, this->center.y()));
    angles.push_back(QPointF(this->center.x() - a * 2 / 3, this->center.y() + b));
    angles.push_back(QPointF(this->center.x() + a * 2 / 3, this->center.y() + b));
    angles.push_back(QPointF(this->center.x() + a, this->center.y()));
    angles.push_back(QPointF(this->center.x() + a * 2 / 3, this->center.y() - b));
    angles.push_back(QPointF(this->center.x() - a * 2 / 3, this->center.y() - b));
    this->countofangles = 6;

}

void Shestiuh::SetWidth(int w)
{
    this->a = w;
    angles[0]=(QPointF(this->center.x() - a, this->center.y()));
    angles[1]=(QPointF(this->center.x() - a * 2 / 3, this->center.y() + b));
    angles[2]=(QPointF(this->center.x() + a * 2 / 3, this->center.y() + b));
    angles[3]=(QPointF(this->center.x() + a, this->center.y()));
    angles[4]=(QPointF(this->center.x() + a * 2 / 3, this->center.y() - b));
    angles[5]=(QPointF(this->center.x() - a * 2 / 3, this->center.y() - b));
}

void Shestiuh::SetHeight(int h)
{
    this->b = h;
    angles[0]=(QPointF(this->center.x() - a, this->center.y()));
    angles[1]=(QPointF(this->center.x() - a * 2 / 3, this->center.y() + b));
    angles[2]=(QPointF(this->center.x() + a * 2 / 3, this->center.y() + b));
    angles[3]=(QPointF(this->center.x() + a, this->center.y()));
    angles[4]=(QPointF(this->center.x() + a * 2 / 3, this->center.y() - b));
    angles[5]=(QPointF(this->center.x() - a * 2 / 3, this->center.y() - b));
}


