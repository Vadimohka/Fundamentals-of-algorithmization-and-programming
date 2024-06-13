#ifndef STAR5_H
#define STAR5_H

#include "figure.h"
#include <QPainter>

class star5 : public figure
{
    Q_OBJECT
public:
    star5();
    ~star5();
    void initialization();
    int R,G,B,PenSize;
private:
    QVector<QPointF> starPoints;
    double outerRadius,innerRadius,alpha,outerX,outerY,innerX,innerY,shiftAngle;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STAR5_H
