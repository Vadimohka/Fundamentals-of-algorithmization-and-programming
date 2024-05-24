#include "Star_8.h"

Star_8::Star_8(){
    this->countofangles = 16;
}

Star_8::Star_8(int cx, int cy, int a, int b)
{
    this->countofangles = 0;
    this->SetCenter(cx, cy);
    angles.push_back(QPointF(this->center.x() - a   * sin(1 * 3.1415 / 4),              this->center.y() + b   * cos(1 * 3.1415 / 4)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(1 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(1 * 3.1415 / 4 + 3.1415 / 8)));
    angles.push_back(QPointF(this->center.x() - a   * sin(2 * 3.1415 / 4),              this->center.y() + b   * cos(2 * 3.1415 / 4)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(2 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(2 * 3.1415 / 4 + 3.1415 / 8)));
    angles.push_back(QPointF(this->center.x() - a   * sin(3 * 3.1415 / 4),              this->center.y() + b   * cos(3 * 3.1415 / 4)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(3 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(3 * 3.1415 / 4 + 3.1415 / 8)));
    angles.push_back(QPointF(this->center.x() - a   * sin(4 * 3.1415 / 4),              this->center.y() + b   * cos(4 * 3.1415 / 4)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(4 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(4 * 3.1415 / 4 + 3.1415 / 8)));
    angles.push_back(QPointF(this->center.x() - a   * sin(5 * 3.1415 / 4),              this->center.y() + b   * cos(5 * 3.1415 / 4)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(5 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(5 * 3.1415 / 4 + 3.1415 / 8)));
    angles.push_back(QPointF(this->center.x() - a   * sin(6 * 3.1415 / 4),              this->center.y() + b   * cos(6 * 3.1415 / 4)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(6 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(6 * 3.1415 / 4 + 3.1415 / 8)));
    angles.push_back(QPointF(this->center.x() - a   * sin(7 * 3.1415 / 4),              this->center.y() + b   * cos(7 * 3.1415 / 4)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(7 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(7 * 3.1415 / 4 + 3.1415 / 8)));
    angles.push_back(QPointF(this->center.x() - a   * sin(8 * 3.1415 / 4),              this->center.y() + b   * cos(8 * 3.1415 / 4)));
    angles.push_back(QPointF(this->center.x() - a/3 * sin(8 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(8 * 3.1415 / 4 + 3.1415 / 8)));
    this->countofangles = 16;

}

void Star_8::SetWidth(int w)
{
    this->a = w;
    angles[0] =(QPointF(this->center.x() - a   * sin(1 * 3.1415 / 4),              this->center.y() + b   * cos(1 * 3.1415 / 4)));
    angles[1] =(QPointF(this->center.x() - a/3 * sin(1 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(1 * 3.1415 / 4 + 3.1415 / 8)));
    angles[2] =(QPointF(this->center.x() - a   * sin(2 * 3.1415 / 4),              this->center.y() + b   * cos(2 * 3.1415 / 4)));
    angles[3] =(QPointF(this->center.x() - a/3 * sin(2 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(2 * 3.1415 / 4 + 3.1415 / 8)));
    angles[4] =(QPointF(this->center.x() - a   * sin(3 * 3.1415 / 4),              this->center.y() + b   * cos(3 * 3.1415 / 4)));
    angles[5] =(QPointF(this->center.x() - a/3 * sin(3 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(3 * 3.1415 / 4 + 3.1415 / 8)));
    angles[6] =(QPointF(this->center.x() - a   * sin(4 * 3.1415 / 4),              this->center.y() + b   * cos(4 * 3.1415 / 4)));
    angles[7] =(QPointF(this->center.x() - a/3 * sin(4 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(4 * 3.1415 / 4 + 3.1415 / 8)));
    angles[8] =(QPointF(this->center.x() - a   * sin(5 * 3.1415 / 4),              this->center.y() + b   * cos(5 * 3.1415 / 4)));
    angles[9] =(QPointF(this->center.x() - a/3 * sin(5 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(5 * 3.1415 / 4 + 3.1415 / 8)));
    angles[10]=(QPointF(this->center.x() - a   * sin(6 * 3.1415 / 4),              this->center.y() + b   * cos(6 * 3.1415 / 4)));
    angles[11]=(QPointF(this->center.x() - a/3 * sin(6 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(6 * 3.1415 / 4 + 3.1415 / 8)));
    angles[12]=(QPointF(this->center.x() - a   * sin(7 * 3.1415 / 4),              this->center.y() + b   * cos(7 * 3.1415 / 4)));
    angles[13]=(QPointF(this->center.x() - a/3 * sin(7 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(7 * 3.1415 / 4 + 3.1415 / 8)));
    angles[14]=(QPointF(this->center.x() - a   * sin(8 * 3.1415 / 4),              this->center.y() + b   * cos(8 * 3.1415 / 4)));
    angles[15]=(QPointF(this->center.x() - a/3 * sin(8 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(8 * 3.1415 / 4 + 3.1415 / 8)));

}

void Star_8::SetHeight(int h)
{
    this->b = h;
    angles[0] =(QPointF(this->center.x() - a   * sin(1 * 3.1415 / 4),              this->center.y() + b   * cos(1 * 3.1415 / 4)));
    angles[1] =(QPointF(this->center.x() - a/3 * sin(1 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(1 * 3.1415 / 4 + 3.1415 / 8)));
    angles[2] =(QPointF(this->center.x() - a   * sin(2 * 3.1415 / 4),              this->center.y() + b   * cos(2 * 3.1415 / 4)));
    angles[3] =(QPointF(this->center.x() - a/3 * sin(2 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(2 * 3.1415 / 4 + 3.1415 / 8)));
    angles[4] =(QPointF(this->center.x() - a   * sin(3 * 3.1415 / 4),              this->center.y() + b   * cos(3 * 3.1415 / 4)));
    angles[5] =(QPointF(this->center.x() - a/3 * sin(3 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(3 * 3.1415 / 4 + 3.1415 / 8)));
    angles[6] =(QPointF(this->center.x() - a   * sin(4 * 3.1415 / 4),              this->center.y() + b   * cos(4 * 3.1415 / 4)));
    angles[7] =(QPointF(this->center.x() - a/3 * sin(4 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(4 * 3.1415 / 4 + 3.1415 / 8)));
    angles[8] =(QPointF(this->center.x() - a   * sin(5 * 3.1415 / 4),              this->center.y() + b   * cos(5 * 3.1415 / 4)));
    angles[9] =(QPointF(this->center.x() - a/3 * sin(5 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(5 * 3.1415 / 4 + 3.1415 / 8)));
    angles[10]=(QPointF(this->center.x() - a   * sin(6 * 3.1415 / 4),              this->center.y() + b   * cos(6 * 3.1415 / 4)));
    angles[11]=(QPointF(this->center.x() - a/3 * sin(6 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(6 * 3.1415 / 4 + 3.1415 / 8)));
    angles[12]=(QPointF(this->center.x() - a   * sin(7 * 3.1415 / 4),              this->center.y() + b   * cos(7 * 3.1415 / 4)));
    angles[13]=(QPointF(this->center.x() - a/3 * sin(7 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(7 * 3.1415 / 4 + 3.1415 / 8)));
    angles[14]=(QPointF(this->center.x() - a   * sin(8 * 3.1415 / 4),              this->center.y() + b   * cos(8 * 3.1415 / 4)));
    angles[15]=(QPointF(this->center.x() - a/3 * sin(8 * 3.1415 / 4 + 3.1415 / 8), this->center.y() + b/3 * cos(8 * 3.1415 / 4 + 3.1415 / 8)));

}



