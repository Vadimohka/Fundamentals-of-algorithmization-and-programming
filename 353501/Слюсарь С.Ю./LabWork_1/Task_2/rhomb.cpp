#include "rhomb.h"

Rhomb::Rhomb(int x1, int y1, int width, int height) : Figure()
{
    x_ = x1;
    y_ = y1;
    width_ = width;
    height_ = height;
}
Rhomb::~Rhomb()
{

}

void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    QPolygon rhomb;
    QPoint p1 = QPoint(x_ * scale_, y_ * scale_);
    QPoint p2 = QPoint((x_ - width_) * scale_ / 2.0, (y_ - height_) * scale_ / 2.0);
    QPoint p3 = QPoint(x_ * scale_, (y_ - height_)* scale_);
    QPoint p4 = QPoint((x_ + width_) * scale_ / 2.0, (y_ - height_) * scale_ / 2.0) ;
    rhomb << p1 << p2 << p3 << p4;
    painter->save();
    painter->rotate(rotationAngle_);
    painter->translate(x_ + width_ / 2, y_ + height_ / 2);
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    painter->drawPolygon(rhomb);

    painter->rotate(90);
    painter->restore();
}

double Rhomb::area()
{
    return width_ * height_ / 2.0 * scale_;
}

double Rhomb::perimetr()
{
    double tr = areaOfTriangle(x_, y_, x_ + width_ / 2.0, y_ - height_, x_ + width_, y_);
    return tr * 2.0 * scale_;
}

QPointF Rhomb::centerOfMass()
{
    xCenter_ = scale_ * ((x_ + x_ + width_) / 2.0 + stop_ + rotateCenterX);
    yCenter_ = scale_ * (((y_ - height_ / 2.0) + (y_ + height_) / 2.0) / 2.0 + rotateCenterY);
    QPointF r;
    r.setX(xCenter_);
    r.setY(yCenter_);
    return r;
}

void Rhomb::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void Rhomb::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void Rhomb::rotate()
{
    if (rotationAngle_ < 90)
    {
        ++rotationAngle_;
        update();
        rotateCenterX = -width_ / 2.0;
        rotateCenterY = height_ / 2.0;
    }
}

void Rhomb::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
        rotateCenterX = width_ / 2.0;
        rotateCenterY = -height_ / 2.0;
    }
}

void Rhomb::scale()
{
    if (scale_ < 1.5) {
        scale_ += 0.01;
        update();
    }
}

void Rhomb::scaleBack()
{
    if (scale_ > 0.5) {
        scale_ -= 0.01;
        update();
    }
}
