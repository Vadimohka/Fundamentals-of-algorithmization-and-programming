#include "rectangle.h"

Rectangle::Rectangle(int x, int y, int width, int height) : Figure()
{
    x_ = x;
    y_ = y;
    width_ = width;
    height_ = height;
}

Rectangle::~Rectangle()
{

}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    painter->save();
    painter->translate(x_ + width_ / 2.0, y_ + height_);
    painter->rotate(rotationAngle_);
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    painter->drawRect(x_, y_, width_ * scale_, height_ * scale_);
    painter->restore();
}

double Rectangle::area()
{
    return width_ * height_ * scale_;
}

double Rectangle::perimetr()
{
    return (width_ + height_) * 2.0 * scale_;
}

QPointF Rectangle::centerOfMass()
{
    xCenter_ = scale_ * (((x_ + (x_ + width_)) / 2.0) + stop_ + rotateCenterX);
    yCenter_ = scale_ * ((y_ + (y_ + height_)) / 2.0 + rotateCenterY);
    QPointF r;
    r.setX(xCenter_);
    r.setY(yCenter_);
    return r;
}

void Rectangle::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void Rectangle::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void Rectangle::rotate()
{
    if (rotationAngle_ < 90)
    {
    ++rotationAngle_;
    update();
    rotateCenterX = -width_ / 4.0;
    rotateCenterY = height_ / 2.0;
    }
}

void Rectangle::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
        rotateCenterX = width_ / 4.0;
        rotateCenterY = height_ / 2.0;
    }
}

void Rectangle::scale()
{
    if (scale_ < 1.5)
    {
        scale_ += 0.01;
        update();
    }
    if (scale_ == 1.5) width_ *= scale_;
}

void Rectangle::scaleBack()
{
    if (scale_ > 0.5)
    {
        scale_ -= 0.01;
        update();
    }
    if (scale_ == 1.5) width_ *= scale_;
}
