#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "widget.h"
#include <QPainter>

class Ellipse : public Widget
{
    Q_OBJECT
public:
    explicit Ellipse(Widget *parent = nullptr);
    void setSpeed(int speed);
private:
    virtual void paintEvent(QPaintEvent *event);
    int speed = 10;

signals:
         //void Move_Left_Clicked(int,int);

public slots:
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
    void remove();

};

#endif // ELLIPSE_H
