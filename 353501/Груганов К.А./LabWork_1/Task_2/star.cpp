#include "star.h"

Star::Star()
{

}

Star::Star(int points, double innerR, double outerR)
{
    this->points=points;
    this->innerR=innerR;
    this->outerR=outerR;
    this->ptsCount=points*2;
    double X;
    double Y;
    double radius;
    double angle=2*3.1415/ptsCount;
    double startAngle=-3.1415/2;
    for(int i=0;i<this->ptsCount;i++){
        radius = i%2 == 0? outerR :innerR;
        X = center.x()+radius*cos(startAngle + angle*i);
        Y = center.y()+radius*sin(startAngle + angle*i);
        pts.push_back(QPointF(X,Y));
    }
}

void Star::updateStar(int points, double innerR, double outerR)
{
    pts.clear();
    this->points=points;
    this->innerR=innerR;
    this->outerR=outerR;
    this->ptsCount=points*2;
    double X;
    double Y;
    double radius;
    double angle1=2*3.1415/ptsCount;
    double startAngle=-3.1415/2;
    for(int i=0;i<this->ptsCount;i++){
        radius = i%2 == 0? outerR :innerR;
        X = center.x()+radius*cos(startAngle + angle1*i);
        Y = center.y()+radius*sin(startAngle + angle1*i);
        pts.push_back(QPointF(X,Y));
    }
    double angle2 = currAngle * 3.1415 / 180;
    QPointF anchor(center.x(), center.y());
    for (int i = 0; i < ptsCount; i++) {
        double dx = anchor.x() + (pts[i].x() - anchor.x()) * cos(angle2) - (pts[i].y() - anchor.y()) * sin(angle2);
        double dy = anchor.y() + (pts[i].x() - anchor.x()) * sin(angle2) + (pts[i].y() - anchor.y()) * cos(angle2);
        pts[i].setX(dx);
        pts[i].setY(dy);
    }
}

void Star::updatePts(int points)
{
    this->points=points;
    if (points < 5) {
        points = 5;
    }
    updateStar(points,innerR,outerR);
}

void Star::updateInnerR(double innerR)
{
    this->innerR=innerR;
    currScale=1;
    updateStar(points,innerR,outerR);
}

void Star::updateOuterR(double outerR)
{
    this->outerR=outerR;
    currScale=1;
    updateStar(points,innerR,outerR);
}

void Star::print(QPainter *p)
{
    Shape::paint(p);
}
