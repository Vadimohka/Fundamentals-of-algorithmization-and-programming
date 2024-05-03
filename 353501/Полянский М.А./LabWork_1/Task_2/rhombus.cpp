#include "rhombus.h"

Rhombus::Rhombus() {
    side = 100;
    angle = 60;
    calculate_points();
}
void Rhombus::calculate_points() {
    points.resize(4);
    pointsy.resize(4);
    pointsx.resize(4);
    double halfDiagonal = side / 2.0;
    double angleRadians = angle * M_PI / 180.0; 
    pointsx[0] = 0.0;
    pointsy[0] = halfDiagonal;
    pointsx[1] = halfDiagonal / std::tan(angleRadians / 2.0);
    pointsy[1] = 0.0;
    pointsx[2] = 0.0;
    pointsy[2] = -halfDiagonal;
    pointsx[3] = -halfDiagonal / std::tan(angleRadians / 2.0);
    pointsy[3] = 0.0;

    points[0] = {pointsx[0], pointsy[0]};
    points[1] = {pointsx[1], pointsy[1]};
    points[2] = {pointsx[2], pointsy[2]};
    points[3] = {pointsx[3], pointsy[3]};
    setCenter(QPointF(centX, centY));
}
void Rhombus::changeangle(double spinangle){
    angle = spinangle;
    calculate_points();
    update();
}
void Rhombus::change_side(double spinside){
    side = spinside;
    calculate_points();
    update();
}
qreal Rhombus::area(){
    double anglerad = angle * M_PI / 180;
    double diagonal = 2 * side * sin(anglerad / 2.0);
    double area = (side * diagonal) / 2.0;
    return area;
}
qreal Rhombus::perimeter(){
    return 4 * side;
}
