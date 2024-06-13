#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "abstractfigure.h"

class Triangle : public AbstractFigure
{
    Q_OBJECT
public:
    Triangle(int x1 =0 , int y1 = 0, int x2 = 150 , int y2 = 150);
    ~Triangle();
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // TRIANGLE_H
