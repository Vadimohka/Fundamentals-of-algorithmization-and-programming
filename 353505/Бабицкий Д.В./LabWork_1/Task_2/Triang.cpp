#include "Triang.h"

Triang::Triang(){
    this->countofangles = 3;
}

Triang::Triang(int cx, int cy, int a, int b)
{
    this->countofangles = 0;
    this->SetCenter(cx, cy);
    angles.push_back(QPointF(this->center.x(), this->center.y() - (b / sqrt(3))));
    angles.push_back(QPointF(this->center.x() + a/2, this->center.y() + b / (2 * sqrt(3))));
    angles.push_back(QPointF(this->center.x() - a/2, this->center.y() + b / (2 * sqrt(3))));
    this->countofangles = 3;

}

void Triang::SetWidth(int w)
{
    this->a = w;
    angles[1] = (QPointF(this->center.x() + a/2, this->center.y() + b / (2 * sqrt(3))));
    angles[2] = (QPointF(this->center.x() - a/2, this->center.y() + b / (2 * sqrt(3))));
}

void Triang::SetHeight(int h)
{
    this->b = h;
    angles[0] = (QPointF(this->center.x(), this->center.y() - (b / sqrt(3))));
}


