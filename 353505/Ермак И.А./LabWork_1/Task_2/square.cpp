#include "square.h"

Square::Square(int x, int y, int sideS, QColor bColor, QColor pColor) {
    positionX = x;
    positionY = y;
    side = sideS;
    PenColor = pColor;
    BrushColor = bColor;
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
        painter->setPen(PenColor);
        painter->setBrush(BrushColor);
        painter->drawRect(positionX, positionY, side, side);
        update();
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

QRectF Square::boundingRect() const {
    return QRectF(positionX - 2 * side, positionY - 2 * side, side * 20, side * 20);
}

double Square::perimetr() {
    return side * 4;
}

double Square::square() {
    return side * side;
}

void Square::setScale(int sideScale)
{
    sideScal = sideScale;
}

void Square::Scale()
{
    if(side < sideScal)
    {
        side++;
    }
    else if(side > sideScal)
    {
        side--;
    }
}
