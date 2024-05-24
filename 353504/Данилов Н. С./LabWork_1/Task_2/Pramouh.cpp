#include "Pramouh.h"


Pramouh::Pramouh(){
    this->countofangles = 4;
}

Pramouh::Pramouh(int cx, int cy, int a, int b)
{
    this->countofangles = 0;
    this->SetCenter(cx, cy);
    angles.push_back(QPointF(this->center.x() - a, this->center.y() - b));
    angles.push_back(QPointF(this->center.x() + a, this->center.y() - b));
    angles.push_back(QPointF(this->center.x() + a, this->center.y() + b));
    angles.push_back(QPointF(this->center.x() - a, this->center.y() + b));
    this->countofangles = 4;

}

void Pramouh::SetWidth(int w)
{
    this->a = w;
    angles[0]=QPointF(this->center.x() - a, this->center.y() - b);
    angles[1]=QPointF(this->center.x() + a, this->center.y() - b);
    angles[2]=QPointF(this->center.x() + a, this->center.y() + b);
    angles[3]=QPointF(this->center.x() - a, this->center.y() + b);
}

void Pramouh::SetHeight(int h)
{
    this->b = h;
    angles[0]=QPointF(this->center.x() - a, this->center.y() - b);
    angles[1]=QPointF(this->center.x() + a, this->center.y() - b);
    angles[2]=QPointF(this->center.x() + a, this->center.y() + b);
    angles[3]=QPointF(this->center.x() - a, this->center.y() + b);
}


