#include "hexagone.h"

Hexagone::Hexagone(int x, int y, int s, QColor bColor, QColor pColor) : form() {
    positionX = x;
    positionY = y;
    side = s;
    BrushColor = bColor;
    PenColor = pColor;
}

void Hexagone::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    QPainterPath *path;
    path = new QPainterPath;
    path->moveTo(positionX, positionY);
    path->lineTo(positionX + side, positionY);
    path->lineTo(positionX + side * 1.5, positionY + side * sqrt(3) / 2);
    path->lineTo(positionX + side, positionY + side * sqrt(3));
    path->lineTo(positionX, positionY + side * sqrt(3));
    path->lineTo(positionX - side / 2, positionY + side * sqrt(3) / 2);
    path->lineTo(positionX, positionY);

    painter->setPen(PenColor);
    painter->setBrush(BrushColor);
    painter->drawPath(*path);


    // painter->setPen(PenColor);
    // painter->setBrush(BrushColor);
    // painter->drawLine(positionX + side / sqrt(2), positionY, positionX + side + side / sqrt(2), positionY);
    // painter->drawLine(positionX + side + side / sqrt(2), positionY, positionX + side + 2 * side / sqrt(2),
    //                   positionY + side / sqrt(2));

    // painter->drawLine(positionX + side + 2 * side / sqrt(2), positionY + side / sqrt(2), positionX + side +
    //                   2 * side / sqrt(2), positionY + side / sqrt(2) + side);

    // painter->drawLine(positionX + side + 2 * side / sqrt(2), positionY + side / sqrt(2) + side, positionX +
    //                   side + side / sqrt(2), positionY + 2 * side / sqrt(2) + side);

    // painter->drawLine(positionX + side / sqrt(2), positionY + side + sqrt(2) * side,positionX + side + side /
    //                   sqrt(2), positionY + side + sqrt(2) * side);
    // painter->drawLine(positionX + side / sqrt(2), positionY + side + sqrt(2) * side, positionX, positionY +
    //                   side + side / sqrt(2));
    // painter->drawLine(positionX, positionY + side + side / sqrt(2), positionX, positionY + side / sqrt(2));
    // painter->drawLine(positionX, positionY + side / sqrt(2), positionX + side / sqrt(2), positionY);

    update();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Hexagone::boundingRect() const {
    return QRectF(positionX - 10 * side, positionY - 10 * side, side * 30, side * 30);
}


double Hexagone::perimetr() {
    return side * 6;
}

double Hexagone::square() {
    return sqrt(3) * 3 * pow(side,2) / 2;
}

void Hexagone::setScale(int sideScale) {
    sideScal = sideScale;
}

void Hexagone::Scale() {
    if(side < sideScal) {
        side++;
    }
    else if(side > sideScal) {
        side--;
    }
    update();
}
