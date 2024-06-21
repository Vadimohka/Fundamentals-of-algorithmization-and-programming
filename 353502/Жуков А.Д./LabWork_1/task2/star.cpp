#include "star.h"

constexpr double ONE_DEV2 = 0.5;

void Star::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPointF SminusE = QPointF(qAbs(getSP().x() - getEP().x()), qAbs(getSP().y() - getEP().y())); //getSP - стартовая getEP - кончная
    double outerRadius = (SminusE.x() < SminusE.y() ?
                              SminusE.x() : SminusE.y()) / 2;
    double innerRadius = outerRadius / 2;
    QPointF center((getEP().x() + getSP().x()) / 2, (getEP().y() + getSP().y()) / 2);

    QPolygonF star;
    double angle = 2 * M_PI / crns; // crns - углы
    int starPerimeter = 0;
    for (int i = 0; i < crns; ++i) {
        double x1 = center.x() - outerRadius * cos(i * angle);
        double y1 = center.y() - outerRadius * sin(i * angle);
        QPointF outerPoint(x1, y1);
        star << outerPoint;

        double x2 = center.x() - innerRadius * cos((i + ONE_DEV2) * angle);
        double y2 = center.y() - innerRadius * sin((i + ONE_DEV2) * angle);
        QPointF innerPoint(x2, y2);
        star << innerPoint;

        starPerimeter += 2 * sqrt(pow(innerPoint.x() - outerPoint.x(), 2) + pow(innerPoint.y() - outerPoint.y(), 2));
    }
    setPerimeter(starPerimeter);
    painter->drawPolygon(star);

    setArea(crns/4 * pow(outerRadius, 2) * sin(M_PI/crns));

    Q_UNUSED(option)
    Q_UNUSED(widget)
}
