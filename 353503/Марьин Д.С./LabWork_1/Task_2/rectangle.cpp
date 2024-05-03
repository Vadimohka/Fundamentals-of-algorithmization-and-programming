#include "rectangle.h"

Rectangle::Rectangle(): Shape()
{}

void Rectangle::setPoints(QVector<QPointF>points)
{
    temp = points;
    a = abs(temp.at(0).x() - temp.at(1).x());
    b = abs(temp.at(0).y() - temp.at(1).y());
    Topleft = QPointF(std::min((qreal)temp.at(0).x(),(qreal)temp.at(1).x()),std::min((qreal)temp.at(0).y(),(qreal)temp.at(1).y()));
    rect = QRectF(Topleft.x(),Topleft.y(),a,b);
    this->set_Center(points);
    center = get_Center();
}

long double Rectangle::square()
{
    return a * b;
}

long double Rectangle::perimetr()
{
    return 2 * (a + b);
}
qreal Rectangle::getSpecificParam_1()
{
    a = rect.width();
    return a;
}
qreal Rectangle::getSpecificParam_2()
{
    b = rect.height();
    return b;
}
void Rectangle::setSpecificParam_1(qreal p)
{
    rect.setWidth(p);
    a = p;
    this->set_Center(temp);
    update();
}
void Rectangle::setSpecificParam_2(qreal p)
{
    rect.setHeight(p);
    b = p;
    this->set_Center(temp);
    update();
}
QRectF Rectangle::boundingRect() const
{
    return rect;
}

void Rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen = QPen(this->getColor());
    pen.setCosmetic(true);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setBrush(this->getBrush());
    painter->drawRect(rect);
}
