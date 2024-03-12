#include "star5.h"
#include<QApplication>
#include<QCoreApplication>

Star5::Star5()
{

}

void Star5::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::black);
    painter->setBrush(Qt::red); // Установка красного цвета заливки

    QPoint points[11];

    for (int i = 0; i < 5; i++) {
        QPoint p_out, p_in;
        p_out = {
        int(0 - radius2 * sin(2 * M_PI / 5 * i)),
        int(0 - radius1 * cos(2 * M_PI / 5 * i))
        };

        p_in = {
            int(0 - (double)radius4 / 2 * sin(2 * M_PI / 5 * i + M_PI / 5)),
            int(0 - (double)radius3 / 2 * cos(2 * M_PI / 5 * i + M_PI / 5))
        };
        points[i * 2] = p_out;
        points[i * 2 + 1] = p_in;
    }

    points[10].rx() = points[0].rx();
    points[10].ry() = points[0].ry();

    painter->drawPolygon(points, 11); // Рисование закрашенного полигона
}
void Star5::updateSizeRadiushaha(double arg1){
    radius3=arg1;
    radius4=arg1;
}
float Star5::area()
{
    return this->getScale() * this->getScale() * (M_PI * radius3 * radius3 + (M_PI * radius4 * radius4 - M_PI * radius3 * radius4) / 3);
}

float Star5::perimeter()
{
    return radius3 * count + radius4 * count * this->getScale();
}
