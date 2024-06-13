#include "house.h"
#include <qnamespace.h>
#include <qpainter.h>

House::House(){}

void House::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget)
{
    // Line::paint(painter, option, widget);
    // painter->save();
    // painter->translate(x, 0);
    // if (wx > 0)
    //     painter->scale(-1, 1);
    /*painter->save();
    painter->translate(x, 0);
    if (wx > 0)
       painter->scale(-1, 1);*/
    painter->setBrush(Qt:: black);

    painter->drawRect(0,50, 200,300);

    painter->setBrush(Qt::gray);
    QPolygon pol;
    pol << QPoint(0,50)<< QPoint (100,-100)<< QPoint(200, 50);
    painter->drawPolygon(pol);

    painter->setBrush(Qt::blue);
    painter->drawRect(110,100, 30,80);
    painter->drawRect(140,100, 30,80);

    // painter->setBrush(Qt::darkCyan);
    // painter->drawRect(0,200,60, 150);

    QPen pen;
    pen.setColor(Qt::white);
    pen.setStyle(Qt::SolidLine);
    painter->setPen(pen);
    QPolygon windowline;
    windowline <<QPoint(109,99)<< QPoint (171,99)<< QPoint(171, 181)<<QPoint(109,181);
    painter->drawPolygon(windowline);
}



