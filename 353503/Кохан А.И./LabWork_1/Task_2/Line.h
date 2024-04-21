#ifndef LINE_H
#define LINE_H

#include "figure.h"

class Line : public Figure
{
    Q_OBJECT

public:
    Line(QPointF point, QObject *parent = 0);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    qreal getSFigure() const override;
    qreal getPFigure() const override;
};


#endif // LINE_H
