#include "triangle.h"
#include <cmath>

Triangle::Triangle()
{

}


Triangle::Triangle(double a,double b,double c)
{
    this->ptsCount=3;
    this->a=a;
    this->b=b;
    this->c=c;

    xA = (b*b + a*a - c*c) / (2*a);
    yA = -sqrt(b*b - xA*xA);
    pts.push_back(QPointF(center.x()-a/2,center.y()+(double)a/(2*sqrt(3))));
    pts.push_back(QPointF(center.x()+a,center.y()));
    pts.push_back(QPointF(center.x()+xA,center.y()+yA));


}

Triangle::~Triangle()
{

}

void Triangle::updateVertices(double a,double b,double c)
{
    this->ptsCount=3;
    this->a=a;
    this->b=b;
    this->c=c;

    xA = (b*b + a*a - c*c) / (2*a);
    yA = -sqrt(b*b - xA*xA);

    posMove=MassCenter();

    if(currScale!=1){
        center.setX(MassCenter().x());
        center.setY(MassCenter().y());
        currScale=1;
        resize();
    }else{
        center.setX(pts[0].x());
        center.setY(pts[0].y());
        pts[0] = QPointF(center.x(),center.y());
        pts[1] = QPointF(center.x()+a,center.y());
        pts[2] = QPointF(center.x()+xA,center.y()+yA);

        double angle = currAngle * 3.1415 / 180;
        QPointF anchor(center.x(), center.y());
        for (int i = 0; i < ptsCount; i++) {
            double dx = anchor.x() + (pts[i].x() - anchor.x()) * cos(angle) - (pts[i].y() - anchor.y()) * sin(angle);
            double dy = anchor.y() + (pts[i].x() - anchor.x()) * sin(angle) + (pts[i].y() - anchor.y()) * cos(angle);
            pts[i].setX(dx);
            pts[i].setY(dy);
        }
    }

}

void Triangle::updateSideA(double a)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        this->a = a;
        updateVertices(a,b,c);
    }
}

void Triangle::updateSideB(double b)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        this->b = b;
        updateVertices(a,b,c);
    }
}

void Triangle::updateSideC(double c)
{
    if (a + b > c && a + c > b && b + c > a)
    {
        this->c = c;
        updateVertices(a,b,c);
    }
}

void Triangle::paint(QPainter *p)
{
    Shape::paint(p);
}
