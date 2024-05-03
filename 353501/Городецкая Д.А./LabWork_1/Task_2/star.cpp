#include "star.h"
#include <QPainter>



Star::Star(QPointF point, int numberStar, QObject *parent) :
    Figure(point,parent)
{    
    num = numberStar;
    Q_UNUSED(point)
}

Star::~Star()
{

}

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::white, 2));
    double r1 = sqrt(pow(startPoint().x() - endPoint().x(), 2) + pow(startPoint().y() - endPoint().y(), 2));
    double r2 = 0.4 * r1;
    QPolygonF polygon;
    for (int i = 0; i < num; i++){ 
        polygon << QPointF(r1 * cos( i * 2 * M_PI / num) + startPoint().x(), r1 * sin( i * 2 * M_PI / num) + startPoint().y())
             << QPointF(r2 * cos( (i + 0.5) * 2 * M_PI / num) + startPoint().x(), r2 * sin( (i + 0.5) * 2 * M_PI / num) + startPoint().y());
    }
    painter->drawPolygon(polygon);
    //  QPointF point = (startPoint()+endPoint())/2;
    // painter->drawEllipse(point.x(), point.y(), 5, 5);

    Q_UNUSED(option)
    Q_UNUSED(widget)
}


double Star::Ploshad(){
    return qAbs((startPoint().x()-endPoint().x())*(startPoint().y()-endPoint().y()));
}

double Star::Perimeter(){
    return (qAbs(startPoint().x()-endPoint().x())+qAbs(startPoint().y()-endPoint().y()))*2;
}