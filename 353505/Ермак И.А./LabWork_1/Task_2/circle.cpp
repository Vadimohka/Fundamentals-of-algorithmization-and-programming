#include "circle.h"

Circle::Circle(int x, int y, int r, QColor bColor, QColor pColor) : form() {
    positionX = x;
    positionY = y;
    radius = r;
    BrushColor = bColor;
    PenColor = pColor;
}

void  Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(PenColor);
    painter->setBrush(BrushColor);
    painter->drawEllipse(positionX, positionY, 2 * radius, 2 * radius);
    update();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Circle::boundingRect() const {
    return QRectF(positionX, positionY, (2 * radius + 1) * 10, (2 * radius + 1) * 10);
}

double Circle::perimetr() {
    return 2 * 3.14 * radius;
}

double Circle::square() {
    return pow(radius, 2) * 3.14;
}

void Circle::SetScale(int radiusScale) {
    radiusScal = radiusScale;
}

void Circle::Scale() {
    if(radius < radiusScal)
    {
        radius++;
    }
    else if(radius > radiusScal)
    {
        radius--;
    }
}
