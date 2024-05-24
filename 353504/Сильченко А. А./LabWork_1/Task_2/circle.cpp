#include "circle.h"

Circle::Circle(Figure *parent) : Figure(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Circle::draw(QPainter *painter){
    int r = qMax(mouseX, mouseY);
    painter->drawEllipse(QPointF(centerX, centerY), r, r);
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

void Circle::findSquare(){
    int r = qMax(mouseX, mouseY);
    S = 3.141592 * r * r;
}

void Circle::findPerimetr(){
    int r = qMax(mouseX, mouseY);
    P = 2 * 3.141592 * qAbs(r);
}
