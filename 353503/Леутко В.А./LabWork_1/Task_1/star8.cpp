#include "star8.h"

star8::star8() {}

star8::~star8()
{

}

void star8::initialization()
{
    area = (8/3) * (h*h - w*w) * sqrt(2);
    now_area = area;
    perimeter = 16 * (h + w);
    now_perimeter = perimeter;
}

void star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(hasFocus() ? QPen(QColor(252, 15, 192), 3) : QPen(QColor(138, 43, 226), 3));
    painter->drawPoint(0, 0);

    outerRadius = h;
    innerRadius = w;
    alpha = (2 * M_PI) / 8.0;

    for (int i = 0; i < 8; ++i)
    {
        outerX = std::cos(i * alpha) * outerRadius;
        outerY = std::sin(i * alpha) * outerRadius;
        innerX = std::cos((i * alpha) + alpha / 2.0) * innerRadius;
        innerY = std::sin((i * alpha) + alpha / 2.0) * innerRadius;

        starPoints.append(QPointF(outerX, outerY));
        starPoints.append(QPointF(innerX, innerY));
    }

    painter->setPen(QPen(QColor(R, G, B), PenSize));
    painter->drawPolygon(starPoints);

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
