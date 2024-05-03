#include "star.h"
#include <iostream>
Star::Star(QPointF point) : Figure(point)
{

}


void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(QPen(Qt::black, 3));

    double outerRadius = sqrt(pow((getSecondPoint().x() - getFirstPoint().x()),2) + pow((getSecondPoint().y() - getFirstPoint().y()), 2)) / 2;
    double innerRadius = sqrt(pow((getSecondPoint().x() - getFirstPoint().x()),2) + pow((getSecondPoint().y() - getFirstPoint().y()), 2)) / 4.5;

    QPolygon star;


    for (int i = 0; i < valueNumberStarPeaks() * 2; ++i) {
       double radius = ((i % 2 == 0) ? outerRadius : innerRadius);

       double angle = i * M_PI / valueNumberStarPeaks();

       int x = getFirstPoint().x() + radius * std::cos(angle);
       int y = getFirstPoint().y() + radius * std::sin(angle);

       star << QPoint(x, y);

    }

    double res = 0;
    double h = outerRadius - innerRadius;
    double a = 2 * innerRadius * qSin(M_PI / valueNumberStarPeaks());
    double s1 = h * a / 2;
    res += valueNumberStarPeaks() * s1;
    res += a * valueNumberStarPeaks() * innerRadius * qCos(M_PI / valueNumberStarPeaks()) / 2;
    double b = qSqrt(h * h + a * a / 4);
    setArea(res);
    setPerimetr(2 * valueNumberStarPeaks() * b);

    painter->drawPolygon(star);

Q_UNUSED(option)
Q_UNUSED(widget)
}

int Star::valueNumberStarPeaks() const{
    return numberStarPeaks;
}

void Star::setNumberStarPeaks(int value) {
    numberStarPeaks = value;
}
