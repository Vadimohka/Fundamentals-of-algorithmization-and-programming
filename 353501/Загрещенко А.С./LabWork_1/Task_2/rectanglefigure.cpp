#include "rectanglefigure.h"

RectangleFigure::RectangleFigure()
{
    rect = QRect(0, 0, 100, 100);
    is_show_borders = false;
}

void RectangleFigure::drawFigure(QPainter *painter)
{
    QBrush brush;
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(selected_fill_color);
    painter->setBrush(brush);

    QPen pen;
    pen.setStyle(Qt::SolidLine);
    pen.setColor(Qt::black);
    painter->setPen(pen);

    painter->drawRect(rect.x(), rect.y(), rect.width(), rect.height());
}

double RectangleFigure::getSquare()
{
    return boundingRect().height() * boundingRect().width();
}

double RectangleFigure::getPerimetr()
{
    return (boundingRect().height() + boundingRect().width())*2;
}
