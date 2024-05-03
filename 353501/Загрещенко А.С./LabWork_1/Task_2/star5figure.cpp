#include "star5figure.h"

Star5Figure::Star5Figure()
{
    rect = QRect(0, 0, 100, 100);
    is_show_borders = false;
    editPolygon();
}

void Star5Figure::drawFigure(QPainter *painter)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(selected_fill_color);
    painter->setBrush(brush);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    painter->setPen(pen);

    painter->drawPolygon(polygon);
}

void Star5Figure::editPolygon()
{
    polygon.clear();
    polygon << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y())
            << QPoint(boundingRect().width()*0.612 + rect.x(), boundingRect().height()*0.345 + rect.y())
            << QPoint(boundingRect().width()*0.976 + rect.x(), boundingRect().height()*0.345 + rect.y())
            << QPoint(boundingRect().width()*0.682 + rect.x(), boundingRect().height()*0.559 + rect.y())
            << QPoint(boundingRect().width()*0.794 + rect.x(), boundingRect().height()*0.905 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.691 + rect.y())
            << QPoint(boundingRect().width()*0.206 + rect.x(), boundingRect().height()*0.905 + rect.y())
            << QPoint(boundingRect().width()*0.318 + rect.x(), boundingRect().height()*0.559 + rect.y())
            << QPoint(boundingRect().width()*0.024 + rect.x(), boundingRect().height()*0.345 + rect.y())
            << QPoint(boundingRect().width()*0.388 + rect.x(), boundingRect().height()*0.345 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y());
}

