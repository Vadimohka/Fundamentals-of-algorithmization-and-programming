#ifndef LINE_H
#define LINE_H

#include "shape.h"

class Line : public Shape
{
public:
    Line(QPointF point, QPointF zero);
    void draw(QPainter *pntr) override;
    double getS() override;
    double getP() override;
    void setSize(QPointF nPoint) override;
};

#endif // LINE_H
