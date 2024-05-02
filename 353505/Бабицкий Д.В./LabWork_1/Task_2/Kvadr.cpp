#include "Kvadr.h"

Kvadr::Kvadr(){
    this->countofangles = 4;
}

Kvadr::Kvadr(int cx, int cy, int a, int b)
{
    this->countofangles = 0;
    this->SetCenter(cx, cy);
    a = round((a + b) / 2.);
    angles.push_back(QPointF(this->center.x() - a, this->center.y() - a));
    angles.push_back(QPointF(this->center.x() + a, this->center.y() - a));
    angles.push_back(QPointF(this->center.x() + a, this->center.y() + a));
    angles.push_back(QPointF(this->center.x() - a, this->center.y() + a));
    this->countofangles = 4;

}

void Kvadr::SetWidth(int w)
{
    this->a = round((w + this->GetWidth())/2.);
    this->b = this->a;
    angles[0]=QPointF(this->center.x() - a, this->center.y() - a);
    angles[1]=QPointF(this->center.x() + a, this->center.y() - a);
    angles[2]=QPointF(this->center.x() + a, this->center.y() + a);
    angles[3]=QPointF(this->center.x() - a, this->center.y() + a);
}

void Kvadr::SetHeight(int h)
{
    this->b = round((h + this->GetHeight())/2.);
    this->a = this->b;
    angles[0]=QPointF(this->center.x() - a, this->center.y() - a);
    angles[1]=QPointF(this->center.x() + a, this->center.y() - a);
    angles[2]=QPointF(this->center.x() + a, this->center.y() + a);
    angles[3]=QPointF(this->center.x() - a, this->center.y() + a);
}


