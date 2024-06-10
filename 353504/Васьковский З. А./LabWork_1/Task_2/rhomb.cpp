#include "rhomb.h"

Rhomb::Rhomb(): Shape()
{
    width = 0;
    height = 0;
}

void Rhomb::setPoints(QVector<QPointF> points)
{
    temp = points;

    width = abs(temp.at(0).x() - temp.at(1).x());
    height = abs(temp.at(0).y() - temp.at(1).y());
    Topleft = QPointF(std::min((qreal)temp.at(0).x(),(qreal)temp.at(1).x()),std::min((qreal)temp.at(0).y(),(qreal)temp.at(1).y()));
    rect = QRectF(Topleft.x(),Topleft.y(),width,height);
    a = sqrt(width*width + height*height)/2;
    this->set_Center(points);
    center = get_Center();
}

long double Rhomb::square()
{
    return 0.5 * height * width;
}

long double Rhomb::perimetr()
{
    return 4 * a;;
}

qreal Rhomb::getSpecificParam_1()
{
    width = rect.width();
    return width;
}
qreal Rhomb::getSpecificParam_2()
{
    height = rect.height();
    return height;
}
void Rhomb::setSpecificParam_1(qreal p)
{
    rect.setWidth(p);
    width = p;
    a = sqrt(width*width + height*height)/2;
    update();
}
void Rhomb::setSpecificParam_2(qreal p)
{
    rect.setHeight(p);
    height = p;
    a = sqrt(width*width + height*height)/2;
    update();
}
QRectF Rhomb::boundingRect() const
{
    return rect;
}

void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPolygon pol;

    QPoint p1 = QPoint(Topleft.x(),Topleft.y() + height / 2);
    QPoint p2 = QPoint(Topleft.x() + width / 2,Topleft.y());

    pol << QPoint(p1.x(),p1.y()) << QPoint(p2.x(),p2.y()) << QPoint(p1.x() + width,p1.y()) << QPoint(p2.x(),p2.y() + height);

    QPen pen = QPen(this->getColor());
    pen.setCosmetic(true);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setBrush(this->getBrush());
    painter->drawPolygon(pol);
}
