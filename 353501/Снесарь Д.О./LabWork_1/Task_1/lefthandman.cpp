#include "lefthandman.h"

LeftHandMan::LeftHandMan()
{

}


QRectF LeftHandMan::boundingRect() const
{
    return QRectF(0,0,200,200);
}


void LeftHandMan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){

    QPen pen1(Qt::black);
    pen1.setWidth(7);
    QPen pen2(Qt::gray);
    pen2.setWidth(4);

    painter->setPen(pen1);
    painter->drawLine(100,100,50,100);
    painter->setPen(pen2);
    painter->drawLine(50,85,50,110);

    painter->setBrush(Qt::red);
    QRect rect (10,65,45,25);
    painter->fillRect(rect, painter->brush());




}
