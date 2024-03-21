#include "Square.h"
#include <QGraphicsRectItem>

Square::Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    if (isDrawing) {
        if (points.size() < 2) {
            return;
        }

        painter->setRenderHint(QPainter::Antialiasing, true);
        QRectF rect(points[0], points[1]);
        painter->drawRect(rect);
    } else {
        painter->setRenderHint(QPainter::Antialiasing, true);
        painter->drawRect(-a/2, -a/2, a, a);
    }
}

float Square::findArea()
{
    float s = this->getScale();
    if (isDrawing) {
        float d = QLineF(points[0], points[1]).length();
        return s*s*d*d;
    } else {
        return s*s*a*a;
    }
}

float Square::findPerimeter()
{
    float s = this->getScale();
    if (isDrawing) {
        float d = QLineF(points[0], points[1]).length();
        return s*4*d;
    } else {
        return 4*a*s;
    }
}

QPoint Square::getCenter()
{
    if (isDrawing) {
        return QPoint((points[0].x()+points[1].x())/2, (points[0].y()+points[1].y())/2);
    } else {
        return QPoint(this->x(), this->y());
    }
}

void Square::setA(int a) {
    this->a = a;
}

int Square::getA() {
    return this->a;
}

void Square::setPoints(const QVector<QPointF>& points) {
    this->points = points;
}


