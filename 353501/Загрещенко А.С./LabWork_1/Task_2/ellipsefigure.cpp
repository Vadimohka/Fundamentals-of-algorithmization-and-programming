#include "ellipsefigure.h"

EllipseFigure::EllipseFigure() {
    rect = QRect(0, 0, 100, 100);
    is_show_borders = false;
}

void EllipseFigure::drawFigure(QPainter *painter) {
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(selected_fill_color);
    painter->setBrush(brush);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    painter->setPen(pen);

    painter->drawEllipse(rect.x(), rect.y(), rect.width(), rect.height());
}

double EllipseFigure::getSquare()
{
    return (boundingRect().width() * boundingRect().height() * 0.785398163);
}

double EllipseFigure::getPerimetr()
{
    double r1 = boundingRect().width()/2;
    double r2 = boundingRect().height()/2;
    return (3*(r1+r2)-sqrt((3*r1+r2)*(3*r2+r1)))*3.1415;
}

