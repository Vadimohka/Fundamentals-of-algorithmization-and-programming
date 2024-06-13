#include "triangle.h"

Triangle::Triangle(int x, int y, int width, int height) : Figure()
{
    x1_ = x;
    y1_ = y;
    x2_ = x + width / 2.0;
    y2_ = y - height;
    x3_ = x + width;
    y3_ = y;
}
Triangle::~Triangle()
{

}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    painter->save();
    painter->rotate(rotationAngle_);
    painter->translate(x3_, y1_);
    QPolygon triangle;
    triangle << QPoint(x1_ * scale_, y1_ * scale_) << QPoint(x2_ * scale_, y2_ * scale_) << QPoint(x3_ * scale_, y3_ * scale_);
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    painter->drawPolygon(triangle);
    painter->restore();
}

double Triangle::area()
{
    return areaOfTriangle(x1_, y1_, x2_, y2_, x3_, y3_) * scale_;
}

double Triangle::perimetr()
{
    return scale_ * distance(x1_, y1_, x2_, y2_) + distance(x1_, y1_, x3_, y3_) + distance(x3_, y3_, x2_, y2_);
}

QPointF Triangle::centerOfMass()
{
    xCenter_ = scale_ * ((x1_ + x2_ + x3_) / 3.0 + stop_ + rotateCenterX);
    yCenter_ = scale_ * ((y1_ + y2_ + y3_) / 3.0 + rotateCenterY);
    QPointF r;
    r.setX(xCenter_);
    r.setY(yCenter_);
    return r;
}

void Triangle::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void Triangle::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void Triangle::rotate()
{
    if (rotationAngle_ < 90)
    {
        ++rotationAngle_;
        update();
        rotateCenterX = -100;
        rotateCenterY = 0;
    }
}

void Triangle::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
        rotateCenterY = -100;
        rotateCenterX = 0;
    }
}

void Triangle::scale()
{
    if (scale_ < 1.5) {
        scale_ += 0.01;
        update();
    }
}

void Triangle::scaleBack()
{
    if (scale_ > 0.5) {
        scale_ -= 0.01;
        update();
    }
}
