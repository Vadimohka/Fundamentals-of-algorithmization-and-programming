#include "myfigure.h"
constexpr double M_PI = 3.14;
#include <QtMath>

MyFigure::MyFigure() = default;

auto MyFigure::Area() -> qreal
{
    return 0;
}

auto MyFigure::Perimeter() -> qreal
{
    return 0;
}

void MyFigure::changeCenterX(int centerX)
{
    center = QPoint(centerX, center.ry());
}

void MyFigure::changeCenterY(int centerY)
{
    center = QPoint(center.rx(), centerY);
}

auto MyFigure::getCenter() -> QPoint
{
    return {center.rx(), center.ry()};
}

void MyFigure::changeHeight(int newHeight)
{
    height = newHeight;
}

void MyFigure::changeWidth(int newWidth)
{
    width = newWidth;
}

void MyFigure::changeSize(int newSize)
{
    size = newSize;
}

void MyFigure::changeRadius(int newRadius)
{
    radius = newRadius;
}

void MyFigure::changeRadius1(int newRadius1)
{
    radius1 = newRadius1;
}

void MyFigure::changeRadius2(int newRadius2)
{
    radius2 = newRadius2;
}

void MyFigure::changeScale(int newScale)
{
    scale = newScale;
}

auto MyFigure::getScale() -> qreal
{
    return scale;
}

void MyFigure::makeFlagTrue()
{
    flag = true;
}

auto MyFigure::boundingRect() const -> QRectF
{
    return {-_boundRectValue, -_boundRectValue, 2*_boundRectValue, 2*_boundRectValue};
}

void MyFigure ::paint(QPainter * /*painter*/,
                      const QStyleOptionGraphicsItem * /*option*/,
                      QWidget * /*widget*/)
{}
