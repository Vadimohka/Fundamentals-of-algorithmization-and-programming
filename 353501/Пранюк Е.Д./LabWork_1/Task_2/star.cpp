#include "star.h"

Star::Star() {}

void Star::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    painter.setBrush(Qt::NoBrush);
    painter.setPen(QPen(Qt::red, 2));
    double r = sqrt(pow(Figure::startPoint.x() - Figure::endPoint.x(), 2) + pow(Figure::startPoint.y() - Figure::endPoint.y(), 2));

    double angleIncrement = 2 * M_PI / n;

    double centerX=(startPoint.x()+endPoint.x())/2;
    double centerY=(startPoint.y()+endPoint.y())/2;

    double b=(startPoint.x()-endPoint.x())/2;
    double a=(startPoint.y()-endPoint.y())/2;

    QPolygonF starPoints;
    for (int i = 0; i < n; ++i)
    {
        double outerX = centerX - b * std::sin(i * angleIncrement);
        double outerY = centerY - a * std::cos(i * angleIncrement);
        starPoints << QPointF(outerX, outerY);

        double innerX = centerX - b/2 * std::sin((i + 0.5) * angleIncrement);
        double innerY = centerY - a/2 * std::cos((i + 0.5) * angleIncrement);
        starPoints << QPointF(innerX, innerY);
    }

    painter.drawPolygon(starPoints);

}
