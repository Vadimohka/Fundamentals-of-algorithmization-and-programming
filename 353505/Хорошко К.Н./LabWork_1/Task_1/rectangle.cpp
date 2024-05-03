#include "rectangle.h"


Rectangle::Rectangle(){
}


void Rectangle::size(int newX1, int newY1, int newW, int newH){
    x1 = newX1;
    y1 = newY1;
    W = newW;
    H = newH;
}

void Rectangle::color(int x, int y, int z){
    color1 = x;
    color2 = y;
    color3 = z;
}

void Rectangle::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QColor my_color(color1, color2, color3);

    painter.setBrush(my_color);
    painter.setPen(Qt::black);
    painter.drawRect(x1, y1, W, H);

    Q_UNUSED(event);
}

Rectangle::~Rectangle(){
}
