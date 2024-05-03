#include "Ship.h"

Ship::Ship() {}

QRectF Ship::boundingRect() const {
    return QRectF(0,0,10,10);
}
void Ship::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::yellow);
    QPolygon pol;
    pol<<QPoint(-190,100)<<QPoint(-120,200)<<QPoint(80,200)<<QPoint(150,100);
    painter->drawPolygon(pol);
    painter->drawLine(-50,100,-50,-100);
}
