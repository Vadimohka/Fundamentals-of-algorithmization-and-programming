#include "circle.h"
Circle::Circle() {}

Circle::~Circle()
{

}
void Circle::initialization()
{
    area = M_PI * pow(radius, 2);
    now_area = area;
    perimeter = 2 * M_PI * radius;
    now_perimeter = perimeter;
}
void Circle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(hasFocus() ? QPen(QColor(255, 166, 21), 3) : QPen(QColor(95, 0, 45), 3));
    painter->drawPoint(0, 0);
    painter->setPen(QPen(QColor(R, G, B), PenSize));
    painter->drawEllipse(-radius, -radius, 2 * radius, 2 * radius);
    QThread::msleep(10);

    double delta = ang - now_ang;
    now_ang += delta / 100;

    double deltaSize = size - now_size;
    now_size += deltaSize / 100;

    now_area = area * now_size * now_size;
    now_perimeter = perimeter * now_size;


    this->setRotation(now_ang);
    this->setScale(now_size);

    if (this->hasFocus())
        Output();

    Q_UNUSED(option);
    Q_UNUSED(widget);
}
