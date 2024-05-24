#include "Star_6.h"

Star_6::Star_6(){
    this->countofangles = 12;
}

Star_6::Star_6(int cx, int cy, int a, int b)
{
    this->countofangles = 0;
    this->SetCenter(cx, cy);
    angles.push_back(QPointF(this->center.x() - a   * sin(1 * 3.1415 / 3), this->center.y() + b   * cos(1 * 3.1415 / 3)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(1 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(1 * 3.1415 / 3 + 3.1415 / 6)));
    angles.push_back(QPointF(this->center.x() - a   * sin(2 * 3.1415 / 3), this->center.y() + b   * cos(2 * 3.1415 / 3)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(2 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(2 * 3.1415 / 3 + 3.1415 / 6)));
    angles.push_back(QPointF(this->center.x() - a   * sin(3 * 3.1415 / 3), this->center.y() + b   * cos(3 * 3.1415 / 3)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(3 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(3 * 3.1415 / 3 + 3.1415 / 6)));
    angles.push_back(QPointF(this->center.x() - a   * sin(4 * 3.1415 / 3), this->center.y() + b   * cos(4 * 3.1415 / 3)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(4 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(4 * 3.1415 / 3 + 3.1415 / 6)));
    angles.push_back(QPointF(this->center.x() - a   * sin(5 * 3.1415 / 3), this->center.y() + b   * cos(5 * 3.1415 / 3)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(5 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(5 * 3.1415 / 3 + 3.1415 / 6)));
    angles.push_back(QPointF(this->center.x() - a   * sin(6 * 3.1415 / 3), this->center.y() + b   * cos(6 * 3.1415 / 3)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(6 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(6 * 3.1415 / 3 + 3.1415 / 6)));
    this->countofangles = 12;

}

void Star_6::SetWidth(int w)
{
    this->a = w;
    angles[0] =(QPointF(this->center.x() - a   * sin(1 * 3.1415 / 3), this->center.y() + b   * cos(1 * 3.1415 / 3)));
    angles[1] =(QPointF(this->center.x() - a/3 * sin(1 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(1 * 3.1415 / 3 + 3.1415 / 6)));
    angles[2] =(QPointF(this->center.x() - a   * sin(2 * 3.1415 / 3), this->center.y() + b   * cos(2 * 3.1415 / 3)));
    angles[3] =(QPointF(this->center.x() - a/3 * sin(2 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(2 * 3.1415 / 3 + 3.1415 / 6)));
    angles[4] =(QPointF(this->center.x() - a   * sin(3 * 3.1415 / 3), this->center.y() + b   * cos(3 * 3.1415 / 3)));
    angles[5] =(QPointF(this->center.x() - a/3 * sin(3 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(3 * 3.1415 / 3 + 3.1415 / 6)));
    angles[6] =(QPointF(this->center.x() - a   * sin(4 * 3.1415 / 3), this->center.y() + b   * cos(4 * 3.1415 / 3)));
    angles[7] =(QPointF(this->center.x() - a/3 * sin(4 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(4 * 3.1415 / 3 + 3.1415 / 6)));
    angles[8] =(QPointF(this->center.x() - a   * sin(5 * 3.1415 / 3), this->center.y() + b   * cos(5 * 3.1415 / 3)));
    angles[9] =(QPointF(this->center.x() - a/3 * sin(5 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(5 * 3.1415 / 3 + 3.1415 / 6)));
    angles[10]=(QPointF(this->center.x() - a   * sin(6 * 3.1415 / 3), this->center.y() + b   * cos(6 * 3.1415 / 3)));
    angles[11]=(QPointF(this->center.x() - a/3 * sin(6 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(6 * 3.1415 / 3 + 3.1415 / 6)));

}

void Star_6::SetHeight(int h)
{
    this->b = h;
    angles[0] =(QPointF(this->center.x() - a   * sin(1 * 3.1415 / 3), this->center.y() + b   * cos(1 * 3.1415 / 3)));
    angles[1] =(QPointF(this->center.x() - a/3 * sin(1 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(1 * 3.1415 / 3 + 3.1415 / 6)));
    angles[2] =(QPointF(this->center.x() - a   * sin(2 * 3.1415 / 3), this->center.y() + b   * cos(2 * 3.1415 / 3)));
    angles[3] =(QPointF(this->center.x() - a/3 * sin(2 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(2 * 3.1415 / 3 + 3.1415 / 6)));
    angles[4] =(QPointF(this->center.x() - a   * sin(3 * 3.1415 / 3), this->center.y() + b   * cos(3 * 3.1415 / 3)));
    angles[5] =(QPointF(this->center.x() - a/3 * sin(3 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(3 * 3.1415 / 3 + 3.1415 / 6)));
    angles[6] =(QPointF(this->center.x() - a   * sin(4 * 3.1415 / 3), this->center.y() + b   * cos(4 * 3.1415 / 3)));
    angles[7] =(QPointF(this->center.x() - a/3 * sin(4 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(4 * 3.1415 / 3 + 3.1415 / 6)));
    angles[8] =(QPointF(this->center.x() - a   * sin(5 * 3.1415 / 3), this->center.y() + b   * cos(5 * 3.1415 / 3)));
    angles[9] =(QPointF(this->center.x() - a/3 * sin(5 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(5 * 3.1415 / 3 + 3.1415 / 6)));
    angles[10]=(QPointF(this->center.x() - a   * sin(6 * 3.1415 / 3), this->center.y() + b   * cos(6 * 3.1415 / 3)));
    angles[11]=(QPointF(this->center.x() - a/3 * sin(6 * 3.1415 / 3 + 3.1415 / 6), this->center.y() + b/3 * cos(6 * 3.1415 / 3 + 3.1415 / 6)));
}



