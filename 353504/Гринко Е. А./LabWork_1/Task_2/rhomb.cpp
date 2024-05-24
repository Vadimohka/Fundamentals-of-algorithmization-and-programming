#include "rhomb.h"

Rhomb::Rhomb()
{

}

Rhomb::Rhomb(double h1, double h2)
{
    this->ptsCount=4;
    this->h1=h1;
    this->h2=h2;
    pts.push_back(QPointF(this->center.x(),this->center.y()-h1));
    pts.push_back(QPointF(this->center.x()+h2,this->center.y()));
    pts.push_back(QPointF(this->center.x(),this->center.y()+h1));
    pts.push_back(QPointF(this->center.x()-h2,this->center.y()));
}

Rhomb::~Rhomb()
{

}

void Rhomb::updateRhomb(double h1, double h2)
{
    currScale=1;
    pts[0]=(QPointF(this->center.x(),this->center.y()-h1));
    pts[1]=(QPointF(this->center.x()+h2,this->center.y()));
    pts[2]=(QPointF(this->center.x(),this->center.y()+h1));
    pts[3]=(QPointF(this->center.x()-h2,this->center.y()));

    double angle = currAngle * 3.1415 / 180;
    QPointF anchor(center.x(), center.y());
    for (int i = 0; i < ptsCount; i++) {
        double dx = anchor.x() + (pts[i].x() - anchor.x()) * cos(angle) - (pts[i].y() - anchor.y()) * sin(angle);
        double dy = anchor.y() + (pts[i].x() - anchor.x()) * sin(angle) + (pts[i].y() - anchor.y()) * cos(angle);
        pts[i].setX(dx);
        pts[i].setY(dy);
    }
}

void Rhomb::updateH1(double h1)
{
    this->h1=h1;
    updateRhomb(h1,h2);
}

void Rhomb::updateH2(double h2)
{
    this->h2=h2;
    updateRhomb(h1,h2);
}

void Rhomb::paint(QPainter *p)
{
    Shape::paint(p);
}
