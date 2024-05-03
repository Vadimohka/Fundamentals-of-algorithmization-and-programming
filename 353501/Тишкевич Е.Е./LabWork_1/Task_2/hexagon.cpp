// #include "hexagon.h"

// Hexagon::Hexagon(){}

// void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
// {
//     painter->setRenderHint(QPainter::Antialiasing, true);
//     QPolygon polygon;
//     polygon << QPoint(-radius*scale,0) << QPoint(-radius*scale / 2, radius*scale * sqrt(3) / 2) << QPoint(radius *scale/ 2,radius * sqrt(3) *scale / 2) << QPoint(radius *scale,0) << QPoint(radius *scale / 2,-radius*scale * sqrt(3) / 2) << QPoint(-radius/2*scale,-radius *scale* sqrt(3)/2);
//     painter->drawPolygon(polygon);
//     painter->setPen(QPen(Qt::red, 3));
//     painter->drawPoint(x,y);
//     painter->setPen(QPen(Qt::darkGreen, 3));
//     painter->drawPoint(0,0);
//     painter->setPen(Qt::black);
// }

// float Hexagon::perim()
// {
//     return 6 * radius * this->getScale();
// }

// float Hexagon::area()
// {
//     return this->getScale() * this->getScale() * 3 * radius * radius * sqrt(3) / 2;
// }


#include "hexagon.h"

Hexagon::Hexagon(int n) : n(n) {}

void Hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    QPolygon polygon;
    for (int i = 0; i < n; ++i) {
        double theta = 2.0 * M_PI * i / n;
        int x = radius * cos(theta);
        int y = radius * sin(theta);
        polygon << QPoint(x*scale, y*scale);
    }
    painter->drawPolygon(polygon);
    painter->setPen(QPen(Qt::red, 3));
    painter->drawPoint(x,y);
    painter->setPen(QPen(Qt::darkGreen, 3));
    painter->drawPoint(0,0);
    painter->setPen(Qt::black);
}

float Hexagon::perim()
{
    return n * radius * this->getScale();
}

float Hexagon::area()
{
    return 0.5 * n * radius * radius * this->getScale() * this->getScale() * sin(2*M_PI/n);
}

void Hexagon::setn(int num)
{
    n=num;
    QGraphicsItem::update();
}
