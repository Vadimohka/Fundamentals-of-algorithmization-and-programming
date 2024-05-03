#include "ellips.h"

Ellips::Ellips(): Shape() {}

void Ellips::setPoints(QVector<QPointF> points)
{
    temp = points;
    this->set_Center(points);
    center = get_Center();
    a = abs(temp.at(0).x() - temp.at(1).x());
    b = abs(temp.at(0).y() - temp.at(1).y());
    Topleft = QPointF(std::min((qreal)temp.at(0).x(),(qreal)temp.at(1).x()),std::min((qreal)temp.at(0).y(),(qreal)temp.at(1).y()));
    rect = QRectF(Topleft.x(),Topleft.y(),a,b);
}

long double Ellips::square()
{
    return M_PI * a * b;
}

long double Ellips::perimetr()
{
    return 2 *M_PI * qSqrt((a*a + b*b)/2);
}

qreal Ellips::getSpecificParam_1()
{
    a = rect.width();
    return a;
}
qreal Ellips::getSpecificParam_2()
{
    b = rect.height();
    return b;
}

void Ellips::setSpecificParam_1(qreal p)
{
    rect.setWidth(p);
    update();
}

void Ellips::setSpecificParam_2(qreal p)
{
    rect.setHeight(p);
    update();
}

QRectF Ellips::boundingRect() const
{
    return QRectF(rect);
}

void Ellips::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
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
