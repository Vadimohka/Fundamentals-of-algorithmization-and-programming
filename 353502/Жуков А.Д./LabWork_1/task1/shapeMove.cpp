#include "shapeMove.h"

constexpr int LEFT_BORDER = 10;
constexpr int Y_1 = 400;
constexpr int SHIP_WIDTH = 300;
constexpr int SHIP_HEIGHT = 100;
constexpr qint16 r = 300;

int ParentShape::getX() { return x1; }

void ParentShape::setX(int a) { x1 = a; }

void ParentShape::move_shape(int w){
    if (getX() >= w - r){
        a = -1;
    }
    if (getX() <= LEFT_BORDER){
        a = 1;
    }
    setX(getX() + 1 * a);
}

QRectF ParentShape::paint()
{
    return {QRectF(getX(), Y_1, SHIP_WIDTH, SHIP_HEIGHT)};
}
