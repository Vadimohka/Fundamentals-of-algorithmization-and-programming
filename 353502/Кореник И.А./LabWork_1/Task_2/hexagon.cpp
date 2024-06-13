#include "hexagon.h"

Hexagon::Hexagon(QWidget* parent)
    : Figure(parent){
    this->setParent(parent);
    points.clear();
    points.resize(6);
}


void Hexagon::setPoints(){
    points[0] = {static_cast<double>(mouseNow.x()), static_cast<double>(mouseNow.y())};
    float angle = M_PI / 3;
    centre = {static_cast<double>(mousePress.x()), static_cast<double>(mousePress.y())};
    r = sqrt(pow(mousePress.x() - mouseNow.x(), 2) + pow(mouseNow.y() - mousePress.y(), 2));
    for (int i = 1; i < 6; i++){
        double pX = centre.x() + qCos(angle) * (points[i - 1].x() - centre.x()) - qSin(angle) * (points[i - 1].y() - centre.y());
        double pY = centre.y() + qSin(angle) * (points[i - 1].x() - centre.x()) + qCos(angle) * (points[i - 1].y() - centre.y());
        points[i] = {pX, pY};
    }

}


void Hexagon::calcPerimetr(){
    r = sqrt(pow(points[0].x() - points[1].x(), 2) + pow(points[0].y() - points[1].y(), 2));
    perimetr = 6 * r;
}


void Hexagon::calcArea(){
    r = sqrt(pow(points[0].x() - points[1].x(), 2) + pow(points[0].y() - points[1].y(), 2));
    area = 3 * r * r * sqrt(3) / 2;
}
