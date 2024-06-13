#include "rhomb.h"

Rhomb::Rhomb(int x1,int y1, int x2, int y2){

    rect = QRectF(x1,y1,x2,y2);
    show_borders = false;
}

Rhomb::~Rhomb()
{

}

void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    brush.setColor(Qt::red);
    brush.setStyle(Qt::SolidPattern);
    painter->setBrush(brush);
    QPolygonF polygon;

    QPointF point1(rect.width() / 2, 0);
    QPointF point2(rect.width(), rect.height() / 2);
    QPointF point3(rect.width() / 2, rect.height());
    QPointF point4(0, rect.height() / 2);

    polygon << point1 << point2 << point3 << point4;

    painter->drawPolygon(polygon);
}
