#ifndef YOURDRAWING_H
#define YOURDRAWING_H
#include "par_polygon.h"

class YourDrawing : public par_polygon
{
public:
    YourDrawing(QVector <QPointF> p);
    void SetStartParams();
    void draw(QPainter *painter);
    QVector <QPointF> getStartParams();
};

#endif // YOURDRAWING_H
