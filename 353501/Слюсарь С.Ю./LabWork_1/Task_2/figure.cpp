#include "figure.h"
Figure::Figure() : QGraphicsItem()
{

}

Figure::~Figure()
{

}

QRectF Figure::boundingRect() const
{
    return QRectF(-200, -200, 1000, 1000);
}

double Figure::distance(int x1, int y1, int x2, int y2)
{
    return sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
}

double Figure::areaOfTriangle(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double halfPer = distance(x1, y1, x2, y2) + distance(x2, y2, x3, y3) + distance(x1, y1, x3, y3);
    double a = distance(x1, y1, x2, y2);
    double b = distance(x1, y1, x3, y3);
    double c = distance(x3, y3, x2, y2);

    return sqrt(halfPer * (halfPer / a) * (halfPer - b) * (halfPer - c));
}

void Figure::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void Figure::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void Figure::rotate()
{
    if (rotationAngle_ < 90)
    {
        ++rotationAngle_;
        update();
    }
}

void Figure::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
    }
}

void Figure::scale()
{
    if (scale_ < 1.5) {
        scale_ += 0.01;
        update();
    }
}

void Figure::scaleBack()
{
    if (scale_ > 0.5) {
        scale_ -= 0.01;
        update();
    }
}
