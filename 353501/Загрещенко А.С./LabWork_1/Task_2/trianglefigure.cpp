#include "trianglefigure.h"

TriangleFigure::TriangleFigure()
{
    rect = QRect(0, 0, 100, 100);
    is_show_borders = false;
    editPolygon();
}

void TriangleFigure::drawFigure(QPainter *painter)
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

double TriangleFigure::getSquare()
{
    return boundingRect().height() * boundingRect().width() * 0.5;
}

void TriangleFigure::editPolygon()
{
    polygon.clear();
    polygon << QPoint(boundingRect().width()/2+rect.x(), boundingRect().top())
            << QPoint(boundingRect().right(), boundingRect().bottom())
            << QPoint(boundingRect().left(), boundingRect().bottom());
}


