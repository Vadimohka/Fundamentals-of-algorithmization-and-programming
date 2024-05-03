#include "otherfigure.h"
#include <QPainter>
#include <cmath>


otherfigure::otherfigure(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

otherfigure::~otherfigure()
{

}

// Реализуем метод отрисовки
void otherfigure::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 10));

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


double otherfigure::Ploshad(){
    return qAbs((startPoint().x()-endPoint().x())*(startPoint().y()-endPoint().y()));
}

double otherfigure::Perimeter(){
    return (qAbs(startPoint().x()-endPoint().x())+qAbs(startPoint().y()-endPoint().y()))*2;
}