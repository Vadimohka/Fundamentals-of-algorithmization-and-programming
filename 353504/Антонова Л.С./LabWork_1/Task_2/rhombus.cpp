#include "rhombus.h"

Rhombus::Rhombus(Figure *parent) : Figure(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Rhombus::draw(QPainter *painter){
    QPolygon polygon;
    polygon << QPoint(centerX, centerY - mouseY)
            << QPoint(centerX - mouseX, centerY)
            << QPoint(centerX, centerY + mouseY)
            << QPoint(centerX + mouseX, centerY);
    painter->drawPolygon(polygon);
}

void Rhombus::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

void Rhombus::findSquare(){
    S = qAbs(mouseX * mouseY) / 2;
}

void Rhombus::findPerimetr(){
    int length = qSqrt((mouseX / 2) * (mouseX / 2) + (mouseY / 2) * (mouseY / 2));
    P = 4 * length;
}
