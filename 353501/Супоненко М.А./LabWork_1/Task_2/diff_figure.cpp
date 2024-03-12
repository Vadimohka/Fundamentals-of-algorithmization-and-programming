#include "diff_figure.h"
#include <QPainter>
#include <cmath>


diff_figure::diff_figure(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

diff_figure::~diff_figure()
{

}

// Реализуем метод отрисовки
void diff_figure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 10));

    // QRectF rect(qMin(endPoint().x(), startPoint().x()),
    //             qMin(endPoint().y(), startPoint().y()),
    //             qMin(qAbs(endPoint().x() - startPoint().x()),qAbs(endPoint().y() - startPoint().y())),
    //             qMin(qAbs(endPoint().x() - startPoint().x()),qAbs(endPoint().y() - startPoint().y())));
    
    // painter->drawRect(rect);

    double distanceX = (startPoint().x() + endPoint().x()) / 2;
    double distanceY = (startPoint().y() + endPoint().y()) / 2;
    QPolygonF polygon;

    polygon << QPointF(qMin(endPoint().x(), startPoint().x()), qMin(endPoint().y(), startPoint().y()))
        << QPointF(distanceX, distanceY)
        << QPointF(qMin(endPoint().x(), startPoint().x()), qMax(endPoint().y(), startPoint().y()))
        << QPointF(distanceX, distanceY)
        << QPointF(qMax(endPoint().x(), startPoint().x()), qMax(endPoint().y(), startPoint().y()))
        << QPointF(distanceX, distanceY)
        << QPointF(qMax(endPoint().x(), startPoint().x()), qMin(endPoint().y(), startPoint().y()))
        << QPointF(distanceX, distanceY);


    painter->drawPolygon(polygon);
    
    Q_UNUSED(option)
    Q_UNUSED(widget)

}


double diff_figure::Ploshad(){
    return qAbs((startPoint().x()-endPoint().x())*(startPoint().y()-endPoint().y()));
}

double diff_figure::Perimeter(){
    return (qAbs(startPoint().x()-endPoint().x())+qAbs(startPoint().y()-endPoint().y()))*2;
}