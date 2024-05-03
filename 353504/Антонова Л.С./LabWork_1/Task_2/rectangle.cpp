#include "rectangle.h"

Rectangle::Rectangle(Figure *parent) : Figure(parent){}

void Rectangle::draw(QPainter *painter){
    QPolygon polygon;
    polygon << QPoint(centerX - mouseX / 2, centerY - mouseY / 2)
            << QPoint(centerX - mouseX / 2, centerY + mouseY / 2)
            << QPoint(centerX + mouseX / 2, centerY + mouseY / 2)
            << QPoint(centerX + mouseX / 2, centerY - mouseY / 2);
    painter->drawPolygon(polygon);
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

void Rectangle::findSquare(){
    S = qAbs(mouseX * mouseY);
}

void Rectangle::findPerimetr(){
    P = 2 * qAbs(mouseX + mouseY);
}
