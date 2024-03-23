#include "figure.h"

Figure::Figure() = default;


QRectF Figure::boundingRect() const{
    return QRectF();
}

void Figure::upScale()
{
    scale += 0.1;
}
void Figure::downScale()
{
    if(scale >= 0.2){
        scale -= 0.1;
    }
}
void Figure::moveRight(){
    moveX += 5;
}
void Figure::moveDown(){
    moveY += 5;
}
void Figure::moveLeft(){
    moveX -= 5;
}
void Figure::moveUp(){
    moveY -= 5;
}

void Figure::setCenter(){
};

void Figure::setValueC(double Value){Q_UNUSED(Value);}
void Figure::setValueB(double Value){Q_UNUSED(Value);}
void Figure::setValueA(double Value){Q_UNUSED(Value);}

void Figure::rotate_right(){
    angle+=5;
}
void Figure::rotate_left(){
    angle-=5;
}
void Figure::setPoints(){

}
void Figure::calculatePoints(){
}

double Figure::findSquare() {
    square = 0;
    int n = points.size();
    for (int i = 0; i < n; ++i) {
        square += points[i].x() * scale * points[(i + 1) % n].y() * scale - points[(i + 1) % n].x() * scale * points[i].y() * scale;
    }
    return qAbs(square) / 2;
}

double Figure::findPerimeter() {
    perimeter = 0;
    if (points.size() > 2) {
        for (int i = 0; i < points.size() - 1; i++) {
            perimeter += sqrt((points[i].y() - points[i + 1].y()) * scale * (points[i].y() - points[i + 1].y()) * scale +
                               (points[i].x() - points[i + 1].x()) * scale  * (points[i].x() - points[i + 1].x())) * scale;
        }

        perimeter += sqrt(
            (points[0].y() - points[points.size() - 1].y()) * scale * (points[0].y() - points[points.size() - 1].y()) * scale +
            (points[0].x() - points[points.size() - 1].x()) * scale * (points[0].x() - points[points.size() - 1].x())) * scale;
    }
    return perimeter;
}

void Figure::clear(){};

void Figure::setRhombWidth(double arg1){};
void Figure::setRhombHeight(double arg1){};

void Figure::setInnerRadius(){};
void Figure::setOuterRadius(){};
void Figure::setInnerRadiusDown(){};
void Figure::setOuterRadiusDown(){};
void Figure::setVertices(int vertices){};

void Figure::setWidthRectangle(double value){};
void Figure::setHeightRectangle(double value){};

void Figure::setMoveX(double arg1){
    moveX = arg1;
}
void Figure::setMoveY(double arg1){
    moveY = arg1;
}
