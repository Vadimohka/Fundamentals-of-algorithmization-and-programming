#include "ellipse.h"

Ellipse::Ellipse(Figure *parent) : Figure(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Ellipse::draw(QPainter *painter){
    painter->drawEllipse(QPointF(centerX, centerY), mouseX, mouseY);
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

void Ellipse::findSquare(){
    S = 3.141592 * qAbs(mouseX * mouseY);
}

void Ellipse::findPerimetr(){
    P = 3.141592 * qAbs(mouseX + mouseY);
}
