#include "Triangle.h"
#include <QGraphicsRectItem>

Triangle::Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (isDrawing) {
        if (points.size() < 3) {
            return;
        }

        painter->setRenderHint(QPainter::Antialiasing, true);
        QPolygonF polygon;
        polygon << points[0] << points[1] << points[2];
        painter->drawPolygon(polygon);
    } else {
        painter->setRenderHint(QPainter::Antialiasing, true);
        QPolygon polygon;
        polygon << QPoint(0, -a/3*sqrt(3)) << QPoint(a*2/3, a/3*sqrt(3)) << QPoint(-a*2/3, a/3*sqrt(3));
        painter->drawPolygon(polygon);
    }
}

float Triangle::findArea()
{
    float s = this->getScale();
    if (isDrawing) {
        float d, b, c, p;
        d = sqrt((points[0].x() - points[1].x())*(points[0].x() - points[1].x()) + (points[0].y() - points[1].y())*(points[0].y() - points[1].y()));
        b = sqrt((points[1].x() - points[2].x())*(points[1].x() - points[2].x()) + (points[1].y() - points[2].y())*(points[1].y() - points[2].y()));
        c = sqrt((points[0].x() - points[2].x())*(points[0].x() - points[2].x()) + (points[0].y() - points[2].y())*(points[0].y() - points[2].y()));
        p = (d+b+c)/2;
        return s*s*sqrt(p*(p-d)*(p-b)*(p-c));
    } else {
        return s*s*a*a*sqrt(3)/4;
    }
}

float Triangle::findPerimeter()
{
    float s = this->getScale();
    if (isDrawing) {
        float d, b, c;
        d = sqrt((points[0].x() - points[1].x())*(points[0].x() - points[1].x()) + (points[0].y() - points[1].y())*(points[0].y() - points[1].y()));
        b = sqrt((points[1].x() - points[2].x())*(points[1].x() - points[2].x()) + (points[1].y() - points[2].y())*(points[1].y() - points[2].y()));
        c = sqrt((points[0].x() - points[2].x())*(points[0].x() - points[2].x()) + (points[0].y() - points[2].y())*(points[0].y() - points[2].y()));
        return s*(d + b + c);
    } else {
        return 3*a*s;
    }
}

QPoint Triangle::getCenter()
{
    if (isDrawing) {
        return QPoint((points[0].x()+points[1].x()+points[2].x())/3, (points[0].y()+points[1].y()+points[2].y())/3);
    } else {
        return QPoint(this->x(), this->y());
    }
}

void Triangle::setA(int a) {
    this->a = a;
}

int Triangle::getA() {
    return this->a;
}

void Triangle::setPoints(const QVector<QPointF>& points) {
    this->points = points;
}

void Triangle::setRotationCenter() {
    QPointF center = getCenter();
    Figure::setRotationCenter(center);
}

void Triangle::rotateRight() {
    setRotationCenter();
    Figure::rotateRight();
}


void Triangle::rotateLeft() {
    setRotationCenter();
    Figure::rotateLeft();
}
