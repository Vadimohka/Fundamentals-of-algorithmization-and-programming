#include "star6figure.h"

Star6Figure::Star6Figure()
{
    rect = QRect(0, 0, 100, 100);
    is_show_borders = false;
    editPolygon();
}

void Star6Figure::drawFigure(QPainter *painter)
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

void Star6Figure::editPolygon()
{
    polygon.clear();
    polygon << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y())
            << QPoint(boundingRect().width()*0.604 + rect.x(), boundingRect().height()*0.320 + rect.y())
            << QPoint(boundingRect().width()*0.933 + rect.x(), boundingRect().height()*0.250 + rect.y())
            << QPoint(boundingRect().width()*0.708 + rect.x(), boundingRect().height()*0.500 + rect.y())
            << QPoint(boundingRect().width()*0.933 + rect.x(), boundingRect().height()*0.750 + rect.y())
            << QPoint(boundingRect().width()*0.604 + rect.x(), boundingRect().height()*0.680 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*1.000 + rect.y())
            << QPoint(boundingRect().width()*0.396 + rect.x(), boundingRect().height()*0.680 + rect.y())
            << QPoint(boundingRect().width()*0.067 + rect.x(), boundingRect().height()*0.750 + rect.y())
            << QPoint(boundingRect().width()*0.292 + rect.x(), boundingRect().height()*0.500 + rect.y())
            << QPoint(boundingRect().width()*0.067 + rect.x(), boundingRect().height()*0.250 + rect.y())
            << QPoint(boundingRect().width()*0.396 + rect.x(), boundingRect().height()*0.320 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y());
}


