#include "MyPolygon.h"

MyPolygon::MyPolygon() {
    QPolygonF polygon;
    polygon << QPointF(0, 0) << QPointF(50, 0) << QPointF(25, 50) << QPointF(0,50) << QPointF(13,25) << QPointF(38,25) ;
    m_polygon = polygon;
}

MyPolygon::~MyPolygon() {}

QRectF MyPolygon::boundingRect() const {
    return m_polygon.boundingRect();
}

void MyPolygon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setBrush(Qt::red);
    painter->drawPolygon(m_polygon);
}
