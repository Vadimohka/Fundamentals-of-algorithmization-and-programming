
#include "rectangle.h"


Rectangle::Rectangle(int x, int y, int w, int h, QColor bColor, QColor pColor) : form() {
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

double Rectangle::square()
{
    return width * height;
}

double Rectangle::perimetr()
{
    return (width + height) * 2;
}

QRectF Rectangle::boundingRect() const
{
    return QRectF(positionX, positionY, (width + 1) * 10, (height + 1) * 10);
}

void Rectangle::setScale(int widthScale, int heightScale)
{
    widthScal = widthScale;
    heightScal = heightScale;
}

void Rectangle::Scale()
{
    if(height < heightScal)
    {
        height++;
    }
    else if(height > heightScal)
    {
        height--;
    }
    if(width < widthScal)
    {
        width++;
    }
    else if(width > widthScal)
    {
        width--;
    }
}
