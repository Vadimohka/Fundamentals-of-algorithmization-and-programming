#include "circle.h"

Circle::Circle(): Shape()
{}
void Circle::setPoints(QVector<QPointF> points)
{
    temp = points;
    QLineF line = QLineF(points.at(0), points.at(1));
    radius = line.length();
    center = points.at(0);
    Topleft = QPointF(temp.at(0).x() - radius,temp.at(0).y() - radius);
    rect = QRectF(Topleft.x(),Topleft.y(),2*radius,2*radius);
}

long double Circle::square()
{
    return M_PI * radius * radius;
}

long double Circle::perimetr()
{
    return 2 * M_PI * radius;
}

qreal Circle::getSpecificParam_1()
{
    return radius;
}

void Circle::setSpecificParam_1(qreal t)
{
    rect = QRectF(rect.center().x() - t,rect.center().y() - t,2*t,2*t);
    radius = t;
}

QRectF Circle::boundingRect() const
{
    return rect;
}

void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen = QPen(this->getColor());
    pen.setCosmetic(true);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setBrush(this->getBrush());
    painter->drawEllipse(rect);
}
