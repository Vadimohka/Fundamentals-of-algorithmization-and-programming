#include "polygon6figure.h"

Polygon6Figure::Polygon6Figure()
{
    rect = QRect(0, 0, 100, 100);
    is_show_borders = false;
    editPolygon();
}

void Polygon6Figure::drawFigure(QPainter *painter)
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

void Polygon6Figure::editPolygon()
{
    polygon.clear();
    polygon << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y())
            << QPoint(boundingRect().width()*0.933 + rect.x(), boundingRect().height()*0.250 + rect.y())
            << QPoint(boundingRect().width()*0.933 + rect.x(), boundingRect().height()*0.750 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*1.000 + rect.y())
            << QPoint(boundingRect().width()*0.067 + rect.x(), boundingRect().height()*0.750 + rect.y())
            << QPoint(boundingRect().width()*0.067 + rect.x(), boundingRect().height()*0.250 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y());
}

