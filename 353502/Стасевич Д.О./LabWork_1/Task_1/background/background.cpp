//
// Created by darina on 3/3/24.
//

#include <QPainter>

#include "background.h"

Background::Background(){

}

QRectF Background::boundingRect() const {
    return QRectF(0, 0, 0, 0);
}

void Background::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget){
    painter->setBrush(Qt::green);
    painter->setPen(Qt::green);
    painter->drawRect(-400, 150, 670, 400);
    painter->setBrush(Qt::cyan);
    painter->setPen(Qt::cyan);
    painter->drawRect(-400, -300, 670, 450);
    painter->setBrush(Qt::yellow);
    painter->setPen(Qt::yellow);
    painter->drawEllipse(-250, -175, 100, 100);

}
