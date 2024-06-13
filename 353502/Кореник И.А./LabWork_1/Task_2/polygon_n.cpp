#include "polygon_n.h"

Polygon_N::Polygon_N(QWidget* parent)
    : Figure(parent) {
    this->setParent(parent);
    points.clear();
}

void Polygon_N::setN(QString data){
    n = data.toInt();
    points.resize(n);
}

void Polygon_N::setPoints(){
    points[0] = {static_cast<double>(mouseNow.x()), static_cast<double>(mouseNow.y())};
    float angle = 2 * M_PI / n;
    centre = {static_cast<double>(mousePress.x()), static_cast<double>(mousePress.y())};
    r = sqrt(pow(mousePress.x() - mouseNow.x(), 2) + pow(mouseNow.y() - mousePress.y(), 2));
    for (int i = 1; i < n; i++){
        double pX = centre.x() + qCos(angle) * (points[i - 1].x() - centre.x()) - qSin(angle) * (points[i - 1].y() - centre.y());
        double pY = centre.y() + qSin(angle) * (points[i - 1].x() - centre.x()) + qCos(angle) * (points[i - 1].y() - centre.y());
        points[i] = {pX, pY};
    }
}


void Polygon_N::calcArea(){
    r = sqrt(pow(points[0].x() - points[1].x(), 2) + pow(points[0].y() - points[1].y(), 2));
    area = n * r * r * qSin(2 * M_PI / n) / 2;
}


void Polygon_N::calcPerimetr(){
    r = sqrt(pow(points[0].x() - points[1].x(), 2) + pow(points[0].y() - points[1].y(), 2));
    perimetr = n * sqrt(pow(points[0].x() - points[n - 1].x(), 2) + pow(points[0].y() - points[n - 1].y(), 2));

}
