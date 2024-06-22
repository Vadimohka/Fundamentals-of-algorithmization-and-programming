#include "rhomb.h"

Rhomb::Rhomb(QObject *parent) {}

qreal Rhomb::findPerimeter() { return 4 * sqrt(100 * 100 + 50 * 50); }

qreal Rhomb::findSquare() { return 200 * 100 / 2; }

void Rhomb::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                  QWidget *widget) {
    for (int i = 0; i <= 3; i++) {
        if (i % 2 == 0)
            points[i] = QPoint(cos(2 * M_PI * i / 4) * 100, 0);
        else
            points[i] = QPoint(0, sin(2 * M_PI * i / 4) * 50);
    }
    QPolygon pol;
    pol << QPoint(points[0]) << QPoint(points[1]) << QPoint(points[2])
        << QPoint(points[3]);
    painter->drawPolygon(pol);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

Rhomb::~Rhomb() {}
