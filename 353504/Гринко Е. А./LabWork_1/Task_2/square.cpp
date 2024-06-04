#include "square.h"

Square::Square(double a)
{
    this->ptsCount=4;
    this->a=a;
    pts.push_back(QPointF(center.x() - a / 2, center.y() - a / 2));
    pts.push_back(QPointF(center.x() + a / 2, center.y() - a / 2));
    pts.push_back(QPointF(center.x() + a / 2, center.y() + a / 2));
    pts.push_back(QPointF(center.x() - a / 2, center.y() + a / 2));

}

void Square::updateSquare(double a)
{

    currScale=1;
    pts[0] = QPointF(center.x() - a / 2, center.y() - a / 2);
    pts[1] = QPointF(center.x() + a / 2, center.y() - a / 2);
    pts[2] = QPointF(center.x() + a / 2, center.y() + a / 2);
    pts[3] = QPointF(center.x() - a / 2, center.y() + a / 2);

    double angle = currAngle * 3.1415 / 180;
    QPointF anchor(center.x(), center.y());
    for (int i = 0; i < ptsCount; i++) {
        double dx = anchor.x() + (pts[i].x() - anchor.x()) * cos(angle) - (pts[i].y() - anchor.y()) * sin(angle);
        double dy = anchor.y() + (pts[i].x() - anchor.x()) * sin(angle) + (pts[i].y() - anchor.y()) * cos(angle);
        pts[i].setX(dx);
        pts[i].setY(dy);
    }
}

Square::~Square()
{

}

void Square::paint(QPainter *p)
{
    Shape::paint(p);
}
