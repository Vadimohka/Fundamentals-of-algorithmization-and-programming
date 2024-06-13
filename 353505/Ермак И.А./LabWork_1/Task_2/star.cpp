#include "star.h"

Star::Star(int x, int y, int s, QColor bColor, QColor pColor) : form() {
    positionX = x;
    positionY = y;
    side = s;
    BrushColor = bColor;
    PenColor = pColor;
}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    Q_UNUSED(option);
    Q_UNUSED(widget);
    QPainterPath *path;
    path = new QPainterPath;
    path->moveTo((0 + positionX) * side / 30, (0 + positionY) * side / 30);
    path->lineTo((20 + positionX) * side / 30, (0 + positionY) * side / 30);
    path->lineTo((28 + positionX) * side / 30, (20 + positionY) * side / 30);
    path->lineTo((36 + positionX) * side / 30, (0 + positionY) * side / 30);
    path->lineTo((56 + positionX) * side / 30, (0 + positionY) * side / 30);
    path->lineTo((37 + positionX) * side / 30, (-12 + positionY) * side / 30);
    path->lineTo((47 + positionX) * side / 30, (-33 + positionY) * side / 30);
    path->lineTo((28 + positionX) * side / 30, (-20 + positionY) * side / 30);
    path->lineTo((9 + positionX) * side / 30, (-33 + positionY) * side / 30);
    path->lineTo((15 + positionX) * side / 30, (-12 + positionY) * side / 30);
    path->lineTo((0 + positionX) * side / 30, (0 + positionY) * side / 30);
    painter->setPen(PenColor);
    painter->setBrush(BrushColor);
    painter->drawPath(*path);
        // painter->setPen(PenColor);
        // painter->setBrush(BrushColor);
        // painter->translate(positionX + side * 2, positionY);
        // painter->rotate(144);
        // painter->translate(positionX + side, positionY);
        // painter->drawLine(positionX, positionY, positionX + side * 2,positionY);
        // painter->translate(positionX + side * 2, positionY);
        // painter->rotate(144);
        // painter->drawLine(positionX, positionY, positionX + side * 2, positionY);
        // painter->translate(positionX + side * 2, positionY);
        // painter->rotate(144);
        // painter->drawLine(positionX, positionY, positionX + side * 2, positionY);
        // painter->translate(positionX + side * 2, positionY);
        // painter->rotate(144);
        // painter->drawLine(positionX, positionY, positionX + side * 2, positionY);
        // painter->translate(positionX + side * 2, positionY);
        // painter->rotate(144);
        // painter->drawLine(positionX, positionY, positionX + side * 2, positionY);
        // painter->translate(positionX + side * 2, positionY);
        // painter->rotate(144);
        update();
        Q_UNUSED(option);
        Q_UNUSED(widget);
}

QRectF Star::boundingRect() const
{
    return QRectF(positionX - 10 * side, positionY - 10 * side, side * 300 + 1, side * 300 + 1);
}

double Star::square()
{
    return pow(side ,2) * 5 / 2 * sin(2 * 3.14 / 5) - 5 * pow(side ,2) * (5 - pow(5, 1/2)) / 4 * tan(3.14 / 5) / 2;
}

double Star::perimetr()
{
    return (5 / 2 * pow(side, 2) * sin(2 * 3.14 / 5) - 5 * pow(side, 2) * (5 - pow(5, 1/2)) / 4 * tan(3.14 / 5) / 2) / 3.33;
}

void Star::setScale(int sideScale)
{
    sideScal = sideScale;
}

void Star::Scale()
{
    if(side < sideScal)
    {
        side++;
    }
    else if(side > sideScal)
    {
        side--;
    }
    update();
}
