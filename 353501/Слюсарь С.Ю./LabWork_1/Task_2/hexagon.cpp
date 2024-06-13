#include "hexagon.h"

Hexagon::Hexagon(int x, int y, int height, int width) : Figure()
{
    height_ = height;
    width_ = width;
    x1_ = x;
    y1_ = y;
    x2_ = x + width_ / 2.0;
    y2_ = y - height_ / 2.0;
    x3_ = x + width_ * 3.0 / 2.0;
    y3_ = y2_;
    x4_ = x + width_ * 2.0;
    y4_ = y;
    x5_ = x3_;
    y5_ = y + height_ / 2.0;
    x6_ = x2_;
    y6_ = y5_;
}
Hexagon::~Hexagon()
{

}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(widget);
    Q_UNUSED(option);

    QPolygon hexagon;
    QPoint p1 = QPoint(x1_ * scale_, y1_ * scale_);
    QPoint p2 = QPoint(x2_ * scale_, y2_ * scale_);
    QPoint p3 = QPoint(x3_ * scale_, y3_ * scale_);
    QPoint p4 = QPoint(x4_ * scale_, y4_ * scale_);
    QPoint p5 = QPoint(x5_ * scale_, y5_ * scale_);
    QPoint p6 = QPoint(x6_ * scale_, y6_ * scale_);
    hexagon << p1 << p2 << p3 << p4 << p5 << p6;
    painter->save();
    painter->rotate(rotationAngle_);
    painter->translate(x1_ + width_, y1_ + height_ / 2);
    painter->setBrush(Qt::blue);
    painter->setPen(Qt::blue);
    painter->drawPolygon(hexagon);
    painter->translate(50, 50);
    painter->rotate(90);
    painter->restore();
}

double Hexagon::area()
{
    double tr1 = areaOfTriangle(x1_, y1_, x2_, y2_, x4_, y4_);
    double tr2 = areaOfTriangle(x2_, y2_, x3_, y3_, x4_, y4_);
    return (tr1 + tr2) * 2 * scale_;
}

double Hexagon::perimetr()
{
    return distance(x1_, y1_, x2_, y2_) + distance(x2_, y2_, x3_, y3_) + distance(x3_, y3_, x4_, y4_) + distance(x4_, x4_, x5_, y5_) + distance(x5_, y5_, x6_, y6_) + distance(x1_, y1_, x6_, y6_);
}

QPointF Hexagon::centerOfMass()
{
    xCenter_ = scale_ * ((x1_ + x4_) / 2.0 + stop_ + rotateCenterY);
    yCenter_ = scale_ * ((y2_ + y6_) / 2.0 + rotateCenterX) ;
    QPointF r;
    r.setX(xCenter_);
    r.setY(yCenter_);
    return r;
}

void Hexagon::move()
{
    if (stop_ <= 100) {
        moveBy(xspeed_, 0);
        stop_ += 2;
    }
}

void Hexagon::moveBack()
{
    if (stop_ >= -100) {
        moveBy(-xspeed_, 0);
        stop_ -= 2;
    }
}

void Hexagon::rotate()
{
    if (rotationAngle_ < 90)
    {
        ++rotationAngle_;
        update();
        rotateCenterX = -x2_;
        rotateCenterY = -y5_;
    }
}

void Hexagon::rotateBack()
{
    if (rotationAngle_ > -90)
    {
        --rotationAngle_;
        update();
        rotateCenterX = -x4_;
        rotateCenterY = y2_;
    }
}

void Hexagon::scale()
{
    if (scale_ < 1.5) {
        scale_ += 0.01;
        update();
    }
}

void Hexagon::scaleBack()
{
    if (scale_ > 0.5) {
        scale_ -= 0.01;
        update();
    }
}
