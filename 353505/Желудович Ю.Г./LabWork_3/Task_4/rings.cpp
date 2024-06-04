#include "rings.h"

Rings::Rings(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    this -> x = x;
    this -> y = y;

    setRect(x,y,width, height);
}

void Rings::SetHaracteristics(double size, double height){
    this -> size = size;
    this -> height = height;
}

QPointF Rings::Pos(){
    return QPoint(x,y);
}

void Rings::Move_up(qreal y){
    moveBy(0,y);
    this -> y += y;
}

void Rings::Move_right(qreal x){
    moveBy(x,0);
    this -> x += x;
}
