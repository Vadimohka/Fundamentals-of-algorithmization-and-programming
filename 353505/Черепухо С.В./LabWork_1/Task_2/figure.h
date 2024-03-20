#ifndef FIGURE_H
#define FIGURE_H

#include <QPainter>
#include <QVector>
#include <math.h>

class figure
{
public:
    figure();

    float perimetr = 0;
    float area = 0;

    QPointF massCenter = QPoint(-1, -1);

    QVector<QPointF> points;

    virtual void findPerimetr();
    virtual void findArea();

    virtual void setPoints(QPoint msBeg, QPoint msNow);
    virtual void draw(QPainter *painter);
    virtual void rotatePoint(QPointF point, float angle);
    virtual void move(QPoint delta);
    virtual void scalingPoint(int ch);
};

#endif // FIGURE_H
