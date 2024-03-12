#include "star6.h"
#include<QApplication>

Star6::Star6()
{

}

void Star6::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::red); // Установка красного цвета заливки

    QPoint points[12];

    for (int i = 0; i < 6; i++) {
        QPoint p_out, p_in;
        p_out = {
            int(0 - radius2 * sin(2 * M_PI / 6 * i)),
            int(0 - radius1 * cos(2 * M_PI / 6 * i))
        };

        p_in = {
            int(0 - (double)radius3 / 2 * sin(2 * M_PI / 6 * i + M_PI / 6)),
            int(0 - (double)radius4 / 2 * cos(2 * M_PI / 6 * i + M_PI / 6))
        };
        points[i * 2] = p_out;
        points[i * 2 + 1] = p_in;
    }

    points[12].rx() = points[0].rx();
    points[12].ry() = points[0].ry();

    painter->drawPolygon(points, 12); // Рисование закрашенного полигона
}

void Star6::updateSizeRadiushaha(double arg1){
    radius3=arg1;
    radius4=arg1;
}

float Star6::area()
{
    return this->getScale() * this->getScale() * (M_PI * radius3 * radius3 + (M_PI * radius4 * radius4 - M_PI * radius3 * radius3) / 5);
}

float Star6::perimeter()
{
    return radius3 * count + radius4 * count * this->getScale();
}

