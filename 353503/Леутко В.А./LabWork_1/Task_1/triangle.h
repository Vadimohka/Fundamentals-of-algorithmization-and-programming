#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"
#include <QPainter>

class triangle : public figure
{
    Q_OBJECT
public:
    triangle();
    ~triangle();
    void initialization();
    int R,G,B,PenSize;
    QVector<QPair<int,int>> cords;
    QPair<int,int> Center = {0,0};
private:
    int maxX = 0,maxY = 0,minX = 1000000000,minY = 1000000000;
    QPolygon triang;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // TRIANGLE_H
