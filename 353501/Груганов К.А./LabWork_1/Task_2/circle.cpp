#include "circle.h"

Circle::Circle()
{

}

Circle::Circle(double R)
{
    this->ptsCount=50;
    double angle=2*3.1415/ptsCount;
    for(int i=0;i<50;i++){
        double X=center.x()+R*cos(angle*i);
        double Y=center.y()+R*sin(angle*i);
        pts.push_back(QPointF(X,Y));
    }
}

void Circle::updateCircle(double R)
{
    pts.clear();
    currScale=1;
    this->R=R;
    this->ptsCount=50;
    double angle=2*3.1415/ptsCount;
    for(int i=0;i<50;i++){
        double X=center.x()+R*cos(angle*i);
        double Y=center.y()+R*sin(angle*i);
        pts.push_back(QPointF(X,Y));
    }
}

void Circle::paint(QPainter *p)
{
    Shape::paint(p);
}
