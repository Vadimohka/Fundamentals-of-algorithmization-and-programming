#include "triangle.h"

void Triangle::size(int newX1, int newY1, int newX2, int newY2, int newX3, int newY3){
    x1 = newX1;
    y1 = newY1;
    x2 = newX2;
    y2 = newY2;
    x3 = newX3;
    y3 = newY3;
}

void Triangle::paintEvent(QPaintEvent *event)
{
    QPolygon polygon;
    QPainter painter(this);
    QColor brown(139, 69, 19);

    polygon << QPoint(x1, y1) << QPoint(x2, y2) << QPoint(x3, y3);

    painter.setBrush(brown);
    painter.setPen(Qt::black);

    painter.drawPolygon(polygon);

    Q_UNUSED(event);
}
