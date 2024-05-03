#include "star8figure.h"

Star8Figure::Star8Figure()
{
    rect = QRect(0, 0, 100, 100);
    is_show_borders = false;
    editPolygon();
}

void Star8Figure::drawFigure(QPainter *painter)
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

void Star8Figure::editPolygon()
{
    polygon.clear();
    polygon << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y())
            << QPoint(boundingRect().width()*0.591 + rect.x(), boundingRect().height()*0.280 + rect.y())
            << QPoint(boundingRect().width()*0.854 + rect.x(), boundingRect().height()*0.146 + rect.y())
            << QPoint(boundingRect().width()*0.720 + rect.x(), boundingRect().height()*0.409 + rect.y())
            << QPoint(boundingRect().width()*1.000 + rect.x(), boundingRect().height()*0.500 + rect.y())
            << QPoint(boundingRect().width()*0.720 + rect.x(), boundingRect().height()*0.591 + rect.y())
            << QPoint(boundingRect().width()*0.854 + rect.x(), boundingRect().height()*0.854 + rect.y())
            << QPoint(boundingRect().width()*0.591 + rect.x(), boundingRect().height()*0.720 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*1.000 + rect.y())
            << QPoint(boundingRect().width()*0.409 + rect.x(), boundingRect().height()*0.720 + rect.y())
            << QPoint(boundingRect().width()*0.146 + rect.x(), boundingRect().height()*0.854 + rect.y())
            << QPoint(boundingRect().width()*0.280 + rect.x(), boundingRect().height()*0.591 + rect.y())
            << QPoint(boundingRect().width()*0.000 + rect.x(), boundingRect().height()*0.500 + rect.y())
            << QPoint(boundingRect().width()*0.280 + rect.x(), boundingRect().height()*0.409 + rect.y())
            << QPoint(boundingRect().width()*0.146 + rect.x(), boundingRect().height()*0.146 + rect.y())
            << QPoint(boundingRect().width()*0.409 + rect.x(), boundingRect().height()*0.280 + rect.y())
            << QPoint(boundingRect().width()*0.500 + rect.x(), boundingRect().height()*0.000 + rect.y());
}
