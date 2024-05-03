#include "rhombus.h"

Rhombus::Rhombus() {}
void Rhombus::calculatePoints() {
    points.resize(4);
    pointsY.resize(4);
    pointsX.resize(4);
    double halfDiagonal = side / 2.0;
    double angleRadians = angle * M_PI / 180.0; // Преобразование угла в радианы
    pointsX[0] = 0.0;
    pointsY[0] = halfDiagonal;
    pointsX[1] = halfDiagonal / std::tan(angleRadians / 2.0);
    pointsY[1] = 0.0;
    pointsX[2] = 0.0;
    pointsY[2] = -halfDiagonal;
    pointsX[3] = -halfDiagonal / std::tan(angleRadians / 2.0);
    pointsY[3] = 0.0;

    points[0] = {pointsX[0], pointsY[0]};
    points[1] = {pointsX[1], pointsY[1]};
    points[2] = {pointsX[2], pointsY[2]};
    points[3] = {pointsX[3], pointsY[3]};
    centerset();
}
void Rhombus::changeAngle(double spinangle){
    angle = spinangle;
    calculatePoints();
}
void Rhombus::changeSide(double spinside){
    side = spinside;
    calculatePoints();
}
qreal Rhombus::calculateArea(){
    double anglerad = angle * M_PI / 180;
    double diagonal = 2 * side * sin(anglerad / 2.0);
    double calculateArea = (side * diagonal) / 2.0;
    return calculateArea;
}
qreal Rhombus::calculatePerimeter(){
    return 4 * side;
}
