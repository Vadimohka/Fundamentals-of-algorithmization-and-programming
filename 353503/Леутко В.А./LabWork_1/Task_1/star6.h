#ifndef STAR6_H
#define STAR6_H

#include "figure.h"
#include <QPainter>

class star6 : public figure
{
    Q_OBJECT
public:
    star6();
    ~star6();
    void initialization();
    int R,G,B,PenSize;
private:
    QVector<QPointF> starPoints;
    double outerRadius,innerRadius,alpha,outerX,outerY,innerX,innerY,shiftAngle;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STAR6_H
