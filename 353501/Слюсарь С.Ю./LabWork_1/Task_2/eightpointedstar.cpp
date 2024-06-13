#include "eightpointedstar.h"

EightPointedStar::EightPointedStar(int x, int y, int radius) : Star()
{
    x_ = x;
    y_ = y;
    radius_ = radius;
}

void EightPointedStar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);
    
    painter->save();
    painter->rotate(rotationAngle_);
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    QPolygonF pol, pol2, pol3, pol4, pol5;
    p[0] = QPointF(x_ * scale_,(y_ - radius_) * scale_);
    p[1] = QPointF((x_ + radius_ * sin(2 * M_PI * 1 / 8)) * scale_, (y_ - radius_ * cos(2 * M_PI * 1 / 8)) * scale_);
    p[2] = QPointF((x_ + radius_ * sin(2 * M_PI * 2 / 8)) * scale_, (y_ - radius_ * cos(2 * M_PI * 2 / 8)) * scale_);
    p[3] = QPointF((x_ + radius_ * sin(2 * M_PI * 3 / 8)) * scale_, (y_ - radius_ * cos(2 * M_PI * 3 / 8)) * scale_);
    p[4] = QPointF((x_ + radius_ * sin(2 * M_PI * 4 / 8)) * scale_, (y_ - radius_ * cos(2 * M_PI * 4 / 8)) * scale_);
    p[5] = QPointF((x_ + radius_ * sin(2 * M_PI * 5 / 8)) * scale_, (y_ - radius_ * cos(2 * M_PI * 5 / 8)) * scale_);
    p[6] = QPointF((x_ + radius_ * sin(2 * M_PI * 6 / 8)) * scale_, (y_ - radius_ * cos(2 * M_PI * 6 / 8)) * scale_);
    p[7] = QPointF((x_ + radius_ * sin(2 * M_PI * 7 / 8)) * scale_, (y_ - radius_ * cos(2 * M_PI * 7 / 8)) * scale_);
    p[8] = QPointF(x_ * scale_, (y_ - radius_) * scale_);
    pol << p[0] << p[3] << p[6] << p[1] << p[4] << p[7] << p[2] << p[5] << p[8];
    pol2 << p[0] << QPoint(0, 0) << p[3];
    pol3 << p[7] << QPoint(0, 0) << p[2];
    pol4 << p[4] << QPoint(0, 0) << p[7];
    pol5 << p[6] << QPoint(0, 0) << p[3];
    painter->drawPolygon(pol);
    painter->drawPolygon(pol2);
    painter->drawPolygon(pol3);
    painter->drawPolygon(pol4);
    painter->drawPolygon(pol5);
    painter->restore();
}

double EightPointedStar::area()
{
    double area = 2 * (1 + sqrt(2)) * pow(radius_, 2) * scale_;
    return area;
}

double EightPointedStar::perimetr()
{
    return distance(p[0], p[1]) + distance(p[1], p[2]) + distance(p[2], p[3]) + distance(p[3], p[4]) + distance(p[4], p[5]) + distance(p[5], p[6]) + distance(p[6], p[7]) + distance(p[7], p[8]);
}

QPointF EightPointedStar::centerOfMass()
{
    for (int i = 0; i < 8; ++i) xCenter_ += p[i].x();
    xCenter_ = (xCenter_ / 8 + stop_);
    for (int i = 0; i < 8; ++i) yCenter_ += p[i].y();
    yCenter_ = 0 * scale_;
    QPointF r;
    r.setX(xCenter_);
    r.setY(yCenter_);
    return r;
}

void EightPointedStar::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void EightPointedStar::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void EightPointedStar::rotate()
{
    if (rotationAngle_ < 90)
    {
        ++rotationAngle_;
        update();
    }
}

void EightPointedStar::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
    }
}

void EightPointedStar::scale()
{
    if (scale_ < 1.5) {
        scale_ += 0.01;
        update();
    }
}

void EightPointedStar::scaleBack()
{
    if (scale_ > 0.5) {
        scale_ -= 0.01;
        update();
    }
}
