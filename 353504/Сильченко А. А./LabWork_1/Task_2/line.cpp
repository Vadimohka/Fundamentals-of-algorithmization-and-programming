#include "line.h"

Line::Line(Figure *parent) : Figure(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Line::draw(QPainter *painter){
    painter->drawLine(QPointF(centerX, centerY), QPointF(mouseX+centerX, mouseY+centerY));
}

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

void Line::findSquare(){
}

void Line::findPerimetr(){
    P = qSqrt((mouseX - centerX) * (mouseX - centerX) + (mouseY - centerY) * (mouseY - centerY));
}
