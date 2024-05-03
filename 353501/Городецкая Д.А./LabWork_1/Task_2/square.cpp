#include "square.h"
#include <QPainter>


Square::Square(QPointF point, QObject *parent) :
    Figure(point,parent)
{
    Q_UNUSED(point)
}

Square::~Square()
{

}


// Реализуем метод отрисовки
void Square::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 2));

    QRectF rect(qMin(endPoint().x(), startPoint().x()),
                qMin(endPoint().y(), startPoint().y()),
                qMin(qAbs(endPoint().x() - startPoint().x()),qAbs(endPoint().y() - startPoint().y())),
                qMin(qAbs(endPoint().x() - startPoint().x()),qAbs(endPoint().y() - startPoint().y())));
    
    painter->drawRect(rect);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}


double Square::Ploshad(){
    return qAbs((startPoint().x()-endPoint().x())*(startPoint().y()-endPoint().y()));
}

double Square::Perimeter(){
    return (qAbs(startPoint().x()-endPoint().x())+qAbs(startPoint().y()-endPoint().y()))*2;
}