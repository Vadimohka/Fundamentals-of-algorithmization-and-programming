#include "hexagon.h"

Hexagon::Hexagon(Figure *parent) : Figure(parent){
    centerX = 0;
    centerY = 0;
    mouseX = 0;
    mouseY = 0;
}

void Hexagon::draw(QPainter *painter){
    QPolygon polygon;
    int sideLength = qMax(mouseX, mouseY);
    for (int i = 0; i < 6; ++i) {
        double angle = 60 * i - 30;  // Угол в градусах
        double radian = qDegreesToRadians(angle);  // Угол в радианах
        int dx = sideLength * cos(radian);
        int dy = sideLength * sin(radian);
        polygon << QPoint(centerX + dx, centerY + dy);
    }
    painter->drawPolygon(polygon);
}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    draw(painter);
}

void Hexagon::findSquare(){
    int sideLength = qMax(mouseX, mouseY);
    S = 3 * qSqrt(3) / 2 * sideLength * sideLength;
}

void Hexagon::findPerimetr(){
    int sideLength = qMax(mouseX, mouseY);
    P = 6 * qAbs(sideLength);
}
