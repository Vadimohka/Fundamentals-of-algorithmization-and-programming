#include "round.h"

Round::Round(int x, int y, int xradius, int yradius) : Figure()
{
    x_ = x;
    y_ = y;
    xradius_ = xradius;
    if (yradius == -1)
    {
        yradius_ = xradius;
    }
    else
    {
        yradius_ = yradius;
    }

}

Round::~Round()
{

}

void Round::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    painter->save();
    painter->rotate(rotationAngle_);
    painter->translate(x_ + xradius_ / 2, y_ + yradius_ / 2);
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    painter->drawEllipse(x_ -xradius_ / 2.0, y_ - yradius_ / 2.0, xradius_ * scale_, yradius_ * scale_);
    painter->restore();
}

double Round::area()
{
    return 3.14 * (xradius_ / 2.0) * (yradius_ / 2.0) * scale_;
}

double Round::perimetr()
{
    return 2.0 * 3.14 * sqrt(((xradius_ / 2.0) * (xradius_ / 2.0) + (yradius_ / 2.0) * (yradius_ / 2.0)) / 2.0) * scale_;
}

QPointF Round::centerOfMass()
{
    xCenter_ = scale_ * (x_ + xradius_ / 2.0 + stop_ + rotateCenterX);
    yCenter_ = scale_ * (y_ + yradius_ / 2.0 + rotateCenterY);
    QPointF r;
    r.setX(xCenter_);
    r.setY(yCenter_);
    return r;
}

void Round::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void Round::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void Round::rotate()
{
    if (rotationAngle_ < 90)
    {
        ++rotationAngle_;
        update();
        rotateCenterX = -xradius_;
        rotateCenterY = 0;
    }
}

void Round::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
        rotateCenterY = -yradius_;
        rotateCenterX = 0;
    }
}
void Round::scale()
{
    if (scale_ < 1.5) {
        scale_ += 0.01;
        update();
    }
}

void Round::scaleBack()
{
    if (scale_ > 0.5) {
        scale_ -= 0.01;
        update();
    }
}
