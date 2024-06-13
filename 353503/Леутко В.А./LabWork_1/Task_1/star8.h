#ifndef STAR8_H
#define STAR8_H

#include "figure.h"
#include <QPainter>

class star8 : public figure
{
    Q_OBJECT
public:
    star8();
    ~star8();
    void initialization();
    int R,G,B,PenSize;
private:
    QVector<QPointF> starPoints;
    double outerRadius,innerRadius,alpha,outerX,outerY,innerX,innerY;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STAR8_H
