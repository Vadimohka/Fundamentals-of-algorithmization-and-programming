#include "rhombusfigure.h"

RhombusFigure::RhombusFigure()
{
    rect = QRect(0, 0, 100, 100);
    is_show_borders = false;
    editPolygon();
}

void RhombusFigure::drawFigure(QPainter *painter)
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

void RhombusFigure::editPolygon()
{
    polygon.clear();
    polygon << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y())
            << QPoint(boundingRect().width()*1.000 + rect.x(), boundingRect().height()*0.500 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*1.000 + rect.y())
            << QPoint(boundingRect().width()*0.000 + rect.x(), boundingRect().height()*0.500 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y());
}

