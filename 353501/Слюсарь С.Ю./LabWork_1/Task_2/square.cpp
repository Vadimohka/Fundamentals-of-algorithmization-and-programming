#include "square.h"

Square::Square(int x, int y, int width) : Figure()
{
    x_ = x;
    y_ = y;
    width_ = width;
}

Square::~Square()
{

}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    painter->save();
    painter->rotate(rotationAngle_);
    painter->translate(x_ + width_ / 2, y_ + width_ / 2);

    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    painter->drawRect(x_, y_, width_ * scale_, width_ * scale_);
    painter->restore();
}

double Square::area()
{
    return scale_ * width_ * width_;
}

double Square::perimetr()
{
    return scale_ * width_ * 4.0;
}

QPointF Square::centerOfMass()
{
    xCenter_ = scale_ * (x_ + (width_ / 2.0) + stop_);
    yCenter_ = scale_ * ((y_ + width_ / 2.0));
    QPointF r;
    r.setX(xCenter_);
    r.setY(yCenter_);
    return r;
}

void Square::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void Square::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void Square::rotate()
{
    if (rotationAngle_ < 90)
    {
        ++rotationAngle_;
        update();
    }
}

void Square::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
    }
}

void Square::scale()
{
    if (scale_ < 1.5) {
        scale_ += 0.01;
        update();
    }
}

void Square::scaleBack()
{
    if (scale_ > 0.5) {
        scale_ -= 0.01;
        update();
    }
}
