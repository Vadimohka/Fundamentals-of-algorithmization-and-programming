#include "sixpointedstar.h"

SixPointedStar::SixPointedStar(int x, int y, int radius) : Star()
{
    x_ = x;
    y_ = y;
    radius_ = radius;
}

void SixPointedStar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    painter->save();
    painter->rotate(rotationAngle_);
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    QPolygonF pol, pol2;
    p[0] = QPointF(x_ * scale_, (y_ - radius_) * scale_);
    p[1] = QPointF((x_ + radius_ * sin(2 * M_PI * 1 / 6)) * scale_, (y_ - radius_ * cos(2 * M_PI * 1 / 6)) * scale_);
    p[2] = QPointF((x_ + radius_ * sin(2 * M_PI * 2 / 6)) * scale_, (y_ - radius_ * cos(2 * M_PI * 2 / 6)) * scale_);
    p[3] = QPointF((x_ + radius_ * sin(2 * M_PI * 3 / 6)) * scale_, (y_ - radius_ * cos(2 * M_PI * 3 / 6)) * scale_);
    p[4] = QPointF((x_ + radius_ * sin(2 * M_PI * 4 / 6)) * scale_, (y_ - radius_ * cos(2 * M_PI * 4 / 6)) * scale_);
    p[5] = QPointF((x_ + radius_ * sin(2 * M_PI * 5 / 6)) * scale_, (y_ - radius_ * cos(2 * M_PI * 5 / 6)) * scale_);
    p[6] = QPointF(x_ * scale_, (y_ - radius_) * scale_);
    pol << p[0] << p[2] << p[4];
    pol2 << p[1] << p[3] << p[5];
    painter->drawPolygon(pol);
    painter->drawPolygon(pol2);
    painter->restore();
}

double SixPointedStar::area()
{
    double area = 3 * sqrt(3) / 2.0 * pow(radius_, 2) * scale_;
    return area;
}

double SixPointedStar::perimetr()
{
    return distance(p[0], p[1]) + distance(p[1], p[2]) + distance(p[2], p[3]) + distance(p[3], p[4]) + distance(p[4], p[5]) + distance(p[5], p[6]);
}

QPointF SixPointedStar::centerOfMass()
{
    for (int i = 0; i < 6; ++i) xCenter_ += p[i].x();
    xCenter_ = xCenter_ / 6 + stop_ ;
    for (int i = 0; i < 6; ++i) yCenter_ += p[i].y();
    yCenter_ = 0 * scale_;
    QPointF r;
    r.setX(xCenter_);
    r.setY(yCenter_);
    return r;
}

void SixPointedStar::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void SixPointedStar::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void SixPointedStar::rotate()
{
    if (rotationAngle_ < 90)
    {
        ++rotationAngle_;
        update();
    }
}

void SixPointedStar::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
    }
}

void SixPointedStar::scale()
{
    if (scale_ < 1.5) {
        scale_ += 0.01;
        update();
    }
}

void SixPointedStar::scaleBack()
{
    if (scale_ > 0.5) {
        scale_ -= 0.01;
        update();
    }
}
