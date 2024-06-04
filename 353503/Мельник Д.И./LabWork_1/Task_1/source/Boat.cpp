//
// Created by dmitry on 10.2.24.
//

#include <Boat.h>

Boat::Boat(QWidget *parent) {
}


void Boat::paintEvent(QPaintEvent *e) {
    Flag::paintEvent(e);
    QPainter painter;
    QPolygon boxPolygon;
    QPen pen;
    pen.setWidth(3);

    painter.begin(this);
    painter.setPen(pen);

    boxPolygon << QPoint(30, 300) << QPoint(470, 300) << QPoint(410, 400) << QPoint(90, 400) ;
    painter.drawPolygon(boxPolygon);
    painter.drawLine(250,30,250,300);

    painter.end();


}

Boat::~Boat() noexcept {
}