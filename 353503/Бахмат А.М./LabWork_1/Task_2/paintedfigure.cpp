#include "paintedfigure.h"

PaintedFigure::PaintedFigure() = default;

void PaintedFigure::paint(QPainter *painter,
                          const QStyleOptionGraphicsItem * /*unused*/,
                          QWidget * /*unused*/)
{
    painter -> setBrush(QColorConstants::Black);
    painter -> setPen(QColorConstants::Black);
    painter->setRenderHint(QPainter::Antialiasing);

    for (auto point : points) {
        painter->drawEllipse(point, scale, scale);
    }
}

void PaintedFigure::pullPoint(const QPointF &pos)
{
    points.push_back(pos - QPoint(x(), y()));
}
