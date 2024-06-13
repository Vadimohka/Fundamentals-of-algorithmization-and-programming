#include "triangle.h"

Triangle::Triangle(int x, int y, int b, int s, QColor bColor,QColor pColor) : form()
{
    positionX = x;
    positionY = y;
    base = b;
    side = s;
    BrushColor = bColor;
    PenColor = pColor;
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(PenColor);
    painter->setBrush(BrushColor);
    QPolygon polygon;
    polygon << QPoint(positionX, positionY + sqrt(pow(side, 2) - pow(base / 2, 2))) << QPoint(positionX + base, positionY
                  + sqrt(pow(side, 2) - pow(base / 2, 2))) << QPoint(positionX + base / 2, positionY);
    painter->drawPolygon(polygon);
    update();
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

QRectF Triangle::boundingRect() const
{
    return QRectF(positionX, positionY, (base + 1) * 10, (sqrt(pow(side, 2) - pow(base / 2, 2)) + 1) * 10);
}

double Triangle::square()
{
    return base * sqrt(pow(side, 2) - pow(base / 2, 2)) / 2;
}

double Triangle::perimetr()
{
    return side * 2 + base;
}

void Triangle::setScale(int baseScale, int sideScale)
{
    baseScal = baseScale;
    sideScal = sideScale;
}

void Triangle::Scale()
{
    if(base < baseScal)
    {
        base++;
    }
    else if(base > baseScal)
    {
        base--;
    }
    if(side < sideScal)
    {
        side++;
    }
    else if(side > sideScal)
    {
        side--;
    }
}
