#include "triangle.h"
#include <QPointF>
#include <cmath>

long double distance(const QPointF& p1, const QPointF& p2)
{
    return std::sqrt(std::pow(p2.x() - p1.x(), 2) + std::pow(p2.y() - p1.y(), 2));
}

double trianglePerimeter(const QPointF& p1, const QPointF& p2, const QPointF& p3)
{
    return distance(p1, p2) + distance(p2, p3) + distance(p3, p1);
}
QPointF setMin(QVector<QPointF>points)
{
    QPointF min = QPointF(points.at(0).x(),points.at(0).y());
    for(auto t :points)
    {
        if(min.x() > t.x())
        {
            min.setX(t.x());
        }
        if(min.y() > t.y())
        {
            min.setY(t.y());
        }
    }
    return min;
}
QPointF setMax(QVector<QPointF>points)
{
    QPointF max = QPointF(points.at(0).x(),points.at(0).y());
    for(auto t :points)
    {
        if(max.x() < t.x())
        {
            max.setX(t.x());
        }
        if(max.y() < t.y())
        {
            max.setY(t.y());
        }
    }
    return max;
}
Triangle::Triangle():Shape()
{
    temp.clear();
}

void Triangle::setPoints(QVector<QPointF>points)
{
    temp.clear();
    temp = points;
    min = setMin(points);
    max = setMax(points);
    set_Center(points);
    center = get_Center();
    setSpecificParam_1(temp.at(0).x());
    setSpecificParam_2(temp.at(0).y());
}

long double Triangle::square()
{
    return  0.5 * abs(temp.at(0).x()*(temp.at(1).y() - temp.at(2).y()) + temp.at(1).x()*(temp.at(2).y() - temp.at(0).y()) + temp.at(2).x()*(temp.at(0).y() - temp.at(1).y()));
}

long double Triangle::perimetr()
{
    return trianglePerimeter(temp.at(0),temp.at(1),temp.at(2));
}
qreal Triangle::getSpecificParam_1()
{
    return temp.at(0).x();
}
qreal Triangle::getSpecificParam_2()
{
    return temp.at(0).y();
}
void Triangle::setSpecificParam_1(qreal p)
{
    temp[0].setX(p);
    min = setMin(temp);
    max = setMax(temp);
    set_Center(temp);
    update();
}
void Triangle::setSpecificParam_2(qreal p)
{
    temp[0].setY(p);
    min = setMin(temp);
    max = setMax(temp);
    set_Center(temp);
    update();
}
QRectF Triangle::boundingRect() const
{
    return QRectF(min,max);
}

void Triangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option)
    Q_UNUSED(widget)

    QPen pen = QPen(this->getColor());
    pen.setCosmetic(true);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setBrush(this->getBrush());

    painter->drawPolygon(temp);
}
