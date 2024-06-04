#include "rectangle.h"

Rectangle::Rectangle()
{

}

Rectangle::Rectangle(double a,double b)
{
    this->ptsCount=4;
    this->a=a;
    this->b=b;
    pts.push_back(QPointF(center.x()-b/2,center.y()-a/2));
    pts.push_back(QPointF(center.x()+b/2,center.y()-a/2));
    pts.push_back(QPointF(center.x()+b/2,center.y()+a/2));
    pts.push_back(QPointF(center.x()-b/2,center.y()+a/2));

}

void Rectangle::updateRect(double a, double b)
{
    currScale=1;
    pts[0] = QPointF(center.x() - b / 2, center.y() - a / 2);
    pts[1] = QPointF(center.x() + b / 2, center.y() - a / 2);
    pts[2] = QPointF(center.x() + b / 2, center.y() + a / 2);
    pts[3] = QPointF(center.x() - b / 2, center.y() + a / 2);


    double angle = currAngle * 3.1415 / 180;
    QPointF anchor(center.x(), center.y());
    for (int i = 0; i < ptsCount; i++) {
        double dx = anchor.x() + (pts[i].x() - anchor.x()) * cos(angle) - (pts[i].y() - anchor.y()) * sin(angle);
        double dy = anchor.y() + (pts[i].x() - anchor.x()) * sin(angle) + (pts[i].y() - anchor.y()) * cos(angle);
        pts[i].setX(dx);
        pts[i].setY(dy);
    }
}

void Rectangle::updateWidth(double width)
{
    this->b = width;
    updateRect(a, b);
}
void Rectangle::updateHeight(double height)
{
    this->a = height;
    updateRect(a, b);
}

void Rectangle::paint(QPainter *p)
{
    Shape::paint(p);
}

Rectangle::~Rectangle()
{

}
