#include "parallelogramm.h"

Parallelogramm::Parallelogramm()
{

}

Parallelogramm::Parallelogramm(double a, double b, double angle)
{
    this->ptsCount=4;
    this->a=a;
    this->b=b;
    this->angle=angle;
    this->radian= angle * 3.1415 / 180.0;
    pts.push_back(QPointF(center.x() + a / 2, center.y() - b * sin(radian) / 2));
    pts.push_back(QPointF(center.x() + a / 5, center.y() + b * sin(radian)/2));
    pts.push_back(QPointF(center.x() - a/2, center.y() + b * sin(radian) / 2));
    pts.push_back(QPointF(center.x() - a / 5, center.y() - b * sin(radian)/2));
}

void Parallelogramm::updateParall(double a, double b,double angle)
{
    this->a=a;
    this->b=b;
    this->angle=angle;
    currScale=1;
    this->radian= angle * 3.1415 / 180.0;
    pts[0]=QPointF(center.x() + a / 2, center.y() - b * sin(radian) / 2);
    pts[1] = QPointF(center.x() + a / 5, center.y() + b * sin(radian)/2);
    pts[2] = QPointF(center.x() - a/2, center.y() + b * sin(radian) / 2);
    pts[3]  = QPointF(center.x() - a / 5, center.y() - b * sin(radian)/2);

    double angle1 = currAngle * 3.1415 / 180;
    QPointF anchor(center.x(), center.y());
    for (int i = 0; i < ptsCount; i++) {
        double dx = anchor.x() + (pts[i].x() - anchor.x()) * cos(angle1) - (pts[i].y() - anchor.y()) * sin(angle1);
        double dy = anchor.y() + (pts[i].x() - anchor.x()) * sin(angle1) + (pts[i].y() - anchor.y()) * cos(angle1);
        pts[i].setX(dx);
        pts[i].setY(dy);
    }
}

void Parallelogramm::updateSideA(double a)
{
    this->a=a;
    updateParall(a,b,angle);
}

void Parallelogramm::updateSideB(double b)
{
    this->b=b;
    updateParall(a,b,angle);
}

void Parallelogramm::paint(QPainter *p)
{
    Shape::paint(p);
}
