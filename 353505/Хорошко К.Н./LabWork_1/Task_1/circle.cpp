#include "circle.h"

void Circle::size(int newX, int newY, int newRadius){
    x = newX;
    y = newY;
    radius = newRadius;
}

void Circle::color(int x, int y, int z){
    color1 = x;
    color2 = y;
    color3 = z;
}

void Circle::paintEvent(QPaintEvent *event){

    QPainter paint(this);
    QColor my_color(color1, color2, color3);


    paint.setPen(Qt::black);
    paint.setBrush(my_color);
    paint.drawEllipse(x, y, 2*radius, 2*radius);

    Q_UNUSED(event);
}
