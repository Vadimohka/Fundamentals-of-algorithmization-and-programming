#include "star6.h"

Star6::Star6() {}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::NoBrush);
    painter->setPen(QPen(QColorConstants::Svg::pink, Figure::k));
    double r = sqrt(pow(Figure::startPoint.x() - Figure::endPoint.x(), 2) + pow(Figure::startPoint.y() - Figure::endPoint.y(), 2));

    double angleIncrement = 2 * M_PI / 6;

    double centerX=(startPoint.x()+endPoint.x())/2;
    double centerY=(startPoint.y()+endPoint.y())/2;

    double b=(startPoint.x()-endPoint.x())/2;
    double a=(startPoint.y()-endPoint.y())/2;

    QPolygonF starPoints;
    for (int i = 0; i < 6; ++i)
    {
        double outerX = centerX - b * std::sin(i * angleIncrement);
        double outerY = centerY - a * std::cos(i * angleIncrement);
        starPoints << QPointF(outerX, outerY);

        double innerX = centerX - b/2 * std::sin((i + 0.5) * angleIncrement);
        double innerY = centerY - a/2 * std::cos((i + 0.5) * angleIncrement);
        starPoints << QPointF(innerX, innerY);
    }

    painter->drawPolygon(starPoints);
    painter->setBrush(Qt::red);
   // painter->drawEllipse((Figure::startPoint.x() + Figure::endPoint.x()) / 2, (Figure::startPoint.y() + Figure::endPoint.y()) / 2, 10,10);

}

float Star6::perimeter()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())+qAbs(Figure::endPoint.x()-Figure::startPoint.x()))*2;
}

float Star6::area()
{
    return (qAbs(Figure::endPoint.y()-Figure::startPoint.y())*qAbs(Figure::endPoint.x()-Figure::startPoint.x()));
}
