#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int w, int h, QColor bColor, QColor pColor) : QGraphicsObject() {
    positionX = x;
    positionY = y;
    width = w;
    height = h;
    PenColor = pColor;
    BrushColor = bColor;
}

void Rectangle::paint(QPainter *painter,const QStyleOptionGraphicsItem *option, QWidget *widget) {

    painter->setPen(PenColor);
    painter->setBrush(BrushColor);
    painter->drawRect(positionX, positionY, width, height);
    update();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(positionX, positionY, width, height);
}

int Rectangle::GetPosX() {
    return positionX;
}

int Rectangle::GetPosY() {
    return positionY;
}

void Rectangle::MoveLeft()
{
    --positionX;
    update();
}

void Rectangle::MoveRight()
{
    ++positionX;
    update();
}

void Rectangle::MoveUp()
{
    --positionY;
    update();
}

void Rectangle::MoveDown()
{
    ++positionY;
    update();
}
