#include "triangle.h"

Triangle::Triangle(int x1,int y1, int x2, int y2){

    rect = QRectF(x1,y1,x2,y2);
    show_borders = false;
}

Triangle::~Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{

    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    QPolygonF polygon;

    QPointF point1(rect.width() / 2, 0);
    QPointF point2(0, rect.height());
    QPointF point3(rect.width(), rect.height());

    polygon << point1 << point2 << point3;

    painter->drawPolygon(polygon);
}
