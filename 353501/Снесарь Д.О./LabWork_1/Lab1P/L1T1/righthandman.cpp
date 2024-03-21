#include "righthandman.h"

RightHandMan::RightHandMan()
{

}

void RightHandMan::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){



    QPen pen1(Qt::black);
    pen1.setWidth(7);
    QPen pen2(Qt::gray);
    pen2.setWidth(4);
    painter->setPen(pen1);
    painter->drawLine(100,100,150,100);
    painter->setPen(pen2);
    painter->drawLine(150,85,150,110);

    painter->setBrush(Qt::green);
    QRect rect (145,65,45,25);
    painter->fillRect(rect, painter->brush());



}
