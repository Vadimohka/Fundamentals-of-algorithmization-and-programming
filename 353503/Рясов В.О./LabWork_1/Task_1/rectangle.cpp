#include "rectangle.h"

Rectangle::Rectangle(QMainWindow *parent)
    : QMainWindow{parent}
{
    rect << QPoint (740,200) << QPoint(825,200) << QPoint(825,550) << QPoint(740,550);
}

/*void Rectangle::paintEvent(QPaintEvent *event)
{
    QPainter painter;

    painter.begin(this);
    QPen pen;
    pen.setColor(Qt::red);
    painter.drawPolygon(rect);
    painter.end();

}*/
