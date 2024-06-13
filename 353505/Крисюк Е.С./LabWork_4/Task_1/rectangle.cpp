#include "rectangle.h"

Rectangle::Rectangle(qreal x, qreal y, qreal width, qreal height, QGraphicsItem* parent) : QGraphicsRectItem(parent)
{
    this -> x = x;
    this -> y = y;

    this -> width = width;
    this -> height = height;

    setRect(x,y,width, height);
}

QPointF Rectangle::Pos(){
    return QPointF(x,y);
}

void Rectangle::SetPos(QPointF point){
    this -> x = point.x();
    this -> y = point.y();
}

void Rectangle::SetColor(QColor color){
    QBrush brush(color);
    this -> setBrush(brush);

}
void Rectangle::SetX(qreal x){
    this -> x = x;
}


qreal Rectangle::GetX(){
    return this -> x;
}

qreal Rectangle::GetY(){
    return this -> y;
}

qreal Rectangle::GetWidth(){
    return this -> width;
}

qreal Rectangle::GetHeight(){
    return this -> height;
}
