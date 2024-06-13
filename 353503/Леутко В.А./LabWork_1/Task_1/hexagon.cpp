#include "hexagon.h"

hexagon::hexagon() {}

hexagon::~hexagon()
{

}

void hexagon::initialization()
{
    area = (3 * sqrt(3) / 2) * h * h;
    now_area = area;
    perimeter = 6 * h;
    now_perimeter = perimeter;
}

void hexagon::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(hasFocus() ? QPen(QColor(252, 15, 192), 3) : QPen(QColor(138, 43, 226), 3));
    painter->drawPoint(0, 0);

    halfSideLength = h / 2.0;
    apothem = sqrt(3) * halfSideLength;

    for (int i = 0; i < 6; ++i)
    {
        angleRad = (M_PI / 180.0) * (60.0 * i - 30.0);
        double x = halfSideLength * cos(angleRad);
        double y = halfSideLength * sin(angleRad);
        hexagonPoints.append(QPointF(x, y));
    }

    painter->setPen(QPen(QColor(R, G, B), PenSize));
    painter->drawPolygon(hexagonPoints);

    // if (filled) {
    //     painter->setBrush(QBrush(QColor(R, G, B)));
    //     painter->drawPolygon(hexagonPoints);
    // } else {
    //     painter->setPen(QPen(QColor(R, G, B), PenSize));
    //     painter->drawPolygon(hexagonPoints);
    // }

    QThread::msleep(5);

    double delta = ang - now_ang;
    now_ang += delta / 10;

    double deltaSize = size - now_size;
    now_size += deltaSize / 10;

    now_area = area * now_size * now_size;
    now_perimeter = perimeter * now_size;

    this->setRotation(now_ang);
    this->setScale(now_size);

    if (this->hasFocus())
        Output();

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
