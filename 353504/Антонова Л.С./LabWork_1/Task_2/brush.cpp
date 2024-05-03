#include "brush.h"

Brush::Brush(Figure *parent) : Figure(parent){\
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
    S = 0;
    P = 0;
}

void Brush::draw(QPainter *painter){
    painter->drawPath(path);
}

void Brush::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

void Brush::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    path.lineTo(event->scenePos());
    update();
}

void Brush::mousePressEvent(QGraphicsSceneMouseEvent *event){
    path.moveTo(event->scenePos());
    update();
}

void Brush::findSquare(){
}

void Brush::findPerimetr(){
}
