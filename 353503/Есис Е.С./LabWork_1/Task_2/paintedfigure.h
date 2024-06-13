#ifndef PAINTEDFIGURE_H
#define PAINTEDFIGURE_H

#include "myfigure.h"

class PaintedFigure : public MyFigure
{
public:
    PaintedFigure();
    void paint(QPainter *painter,
               const QStyleOptionGraphicsItem * /*unused*/,
               QWidget * /*unused*/) override;
    void pullPoint(const QPointF &pos);
    QVector <QPointF> points;
};

#endif // PAINTEDFIGURE_H
