#include "ellipse.h"

Ellipse::Ellipse(int x, int y, int rH, int rV, QColor bColor, QColor pColor) : form() {
    positionX = x;
    positionY = y;
    radiusHorisontal = rH;
    radiusVertical = rV;
    BrushColor = bColor;
    PenColor = pColor;
}

void Ellipse::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) {
    painter->setPen(PenColor);
    painter->setBrush(BrushColor);
    painter->drawEllipse(positionX, positionY, 2 * radiusHorisontal, 2 * radiusVertical);
    update();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Ellipse::boundingRect() const {
    return QRectF(positionX, positionY, (2 * radiusHorisontal + 1) * 10, (2 * radiusVertical + 1) * 10);
}

double Ellipse::perimetr() {
    return (3.14 * radiusHorisontal * radiusVertical + pow(radiusHorisontal - radiusVertical, 2))/(radiusHorisontal + radiusVertical) * 4;
}

double Ellipse::square() {
    return 3.14 * radiusHorisontal * radiusVertical;
}

void Ellipse::setScale(int radiusHScale, int radiusVScale) {
    radiusHScal = radiusHScale;
    radiusVScal = radiusVScale;
}

void Ellipse::Scale() {

    if(radiusHorisontal < radiusHScal)
    {
        radiusHorisontal++;
    }
    else if(radiusHorisontal > radiusHScal)
    {
        radiusHorisontal--;
    }
    if(radiusVertical < radiusVScal)
    {
        radiusVertical++;
    }
    else if(radiusVertical > radiusVScal)
    {
        radiusVertical--;
    }
}
