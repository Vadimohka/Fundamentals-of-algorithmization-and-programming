#include "star8.h"
#include "qapplication.h"
#include<QApplication>

Star8::Star8()
{

}

void Star8::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->setRenderHint(QPainter::Antialiasing, true);
    painter->setPen(Qt::red);
    painter->setBrush(Qt::red); // Установка красного цвета заливки

    QPoint points[17];

    for (int i = 0; i < 8; i++) {
        QPoint p_out, p_in;
        p_out = {
            int(0 - radius2 * sin(2 * M_PI / 8 * i)),
            int(0 - radius1 * cos(2 * M_PI / 8 * i))
        };

        p_in = {
            int(0 - (double)radius4 / 2 * sin(2 * M_PI / 8 * i + M_PI / 8)),
            int(0 - (double)radius3 / 2 * cos(2 * M_PI / 8 * i + M_PI / 8))
        };
        points[i * 2] = p_out;
        points[i * 2 + 1] = p_in;
    }

    points[16].rx() = points[0].rx();
    points[16].ry() = points[0].ry();

    painter->drawPolygon(points, 17); // Рисование закрашенного полигона
}
void Star8::updateSizeRadiushaha(double arg1){
    radius3=arg1;
    radius4=arg1;
}
float Star8::area()
{
    return this->getScale() * this->getScale() * (M_PI * radius3 * radius3 + (M_PI * radius4 * radius4 - M_PI * radius3 * radius4) / 4);
}

float Star8::perimeter()
{
    return radius3 * count + radius4 * count * this->getScale();
}
