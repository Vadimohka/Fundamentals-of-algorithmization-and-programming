#include "rectangle.h"

Rectangle::Rectangle() {}
void Rectangle::calculatePoints() {
    points.resize(4);
    pointsX.resize(4);
    pointsY.resize(4);

    pointsX[0] = 0;
    pointsY[0] = 0;

    pointsX[1] = width;
    pointsY[1] = 0;

    pointsX[2] = width;
    pointsY[2] = height;

    pointsX[3] = 0;
    pointsY[3] = height;

    for (int i = 0; i < 4; ++i) {
        points[i] = QPointF(pointsX[i], pointsY[i]);
    }
    centerset();
}
qreal Rectangle::calculateArea(){
    return height * width;
}
qreal Rectangle::calculatePerimeter(){
    return (height + width) * 2;
}
void Rectangle::changeHeight(double spinheight){
    height = spinheight;
    calculatePoints();
}
void Rectangle::changeWidth(double spinwidth){
    width = spinwidth;
    calculatePoints();
}
