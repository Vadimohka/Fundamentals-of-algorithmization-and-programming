#include "Star_5.h"

Star_5::Star_5(){
    this->countofangles = 5;
}

Star_5::Star_5(int cx, int cy, int a, int b)
{
    this->countofangles = 0;
    this->SetCenter(cx, cy);
    angles.push_back(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 1), this->center.y() - b * cos(72 / 180. * 3.1415 * 1)));
    angles.push_back(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 3), this->center.y() - b * cos(72 / 180. * 3.1415 * 3)));
    angles.push_back(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 5), this->center.y() - b * cos(72 / 180. * 3.1415 * 5)));
    angles.push_back(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 2), this->center.y() - b * cos(72 / 180. * 3.1415 * 2)));
    angles.push_back(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 4), this->center.y() - b * cos(72 / 180. * 3.1415 * 4)));

    this->countofangles = 5;

}

void Star_5::SetWidth(int w)
{
    this->a = w;
    angles[0]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 1), this->center.y() - b * cos(72 / 180. * 3.1415 * 1)));
    angles[1]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 3), this->center.y() - b * cos(72 / 180. * 3.1415 * 3)));
    angles[2]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 5), this->center.y() - b * cos(72 / 180. * 3.1415 * 5)));
    angles[3]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 2), this->center.y() - b * cos(72 / 180. * 3.1415 * 2)));
    angles[4]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 4), this->center.y() - b * cos(72 / 180. * 3.1415 * 4)));
}

void Star_5::SetHeight(int h)
{
    this->b = h;
    angles[0]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 1), this->center.y() - b * cos(72 / 180. * 3.1415 * 1)));
    angles[1]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 3), this->center.y() - b * cos(72 / 180. * 3.1415 * 3)));
    angles[2]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 5), this->center.y() - b * cos(72 / 180. * 3.1415 * 5)));
    angles[3]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 2), this->center.y() - b * cos(72 / 180. * 3.1415 * 2)));
    angles[4]=(QPointF(this->center.x() - a * sin(72 / 180. * 3.1415 * 4), this->center.y() - b * cos(72 / 180. * 3.1415 * 4)));
}


