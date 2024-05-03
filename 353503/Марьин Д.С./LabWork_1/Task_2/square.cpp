#include "square.h"

Square::Square() {}

void Square::setPoints(QVector<QPointF>points)
{
    temp = points;
    QLineF line = QLineF(points.at(0), points.at(1));
    a = line.length();
    a = a / qSqrt(2);
    Topleft = QPointF(std::min((qreal)temp.at(0).x(),(qreal)temp.at(1).x()),std::min((qreal)temp.at(0).y(),(qreal)temp.at(1).y()));
    rect = QRectF(Topleft.x(),Topleft.y(),a,a);
    this->set_Center(points);
    center = get_Center();
}

long double Square::square()
{
    return a * a;
}

long double Square::perimetr()
{
    return 4 * a;
}

qreal Square::getSpecificParam_1()
{
    return a;
}

void Square::setSpecificParam_1(qreal t)
{
    rect = QRectF(rect.center().x() - t/2,rect.center().y() - t/2,t,t);
    a = t;
}

QRectF Square::boundingRect() const
{
    return rect;
}

void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
