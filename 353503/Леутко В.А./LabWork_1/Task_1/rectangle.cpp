#include "rectangle.h"

rectangle::rectangle() {}

rectangle::~rectangle()
{

}

void rectangle::initialization()
{
    area = w*h;
    now_area = area;
    perimeter = 2*w+2*h;
    now_perimeter = perimeter;
}

void rectangle::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setPen(hasFocus() ? QPen(QColor(252, 15, 192), 3) : QPen(QColor(138, 43, 226), 3));
    painter->drawPoint(0, 0);

    if (filled) {
        painter->setBrush(QBrush(QColor(R, G, B)));
        painter->drawRect(-w / 2, -h / 2, w, h);
    } else {
        painter->setPen(QPen(QColor(R, G, B), PenSize));
        painter->drawRect(-w / 2, -h / 2, w, h);
    }

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
