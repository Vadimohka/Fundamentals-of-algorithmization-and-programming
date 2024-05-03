#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"

class Rectangle :  public Figure
{

 public:
     explicit Rectangle(QPointF point);

 private:
     void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RECTANGLE_H
