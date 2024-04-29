#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "commonfigure.h"

class Rectangle : public CommonFigure
{
    Q_OBJECT
public:
    Rectangle(QWidget *parent);


    virtual void draw(QPainter *event) override;


    virtual void drawMoveEvent(QMouseEvent *event) override;
};

#endif // RECTANGLE_H
