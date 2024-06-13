#ifndef CIRCLE_H
#define CIRCLE_H
#include "figure.h"
class Circle : public Figure
{
    Q_OBJECT
public:
    explicit Circle(QWidget *parent = nullptr);

    void draw(QPainter*) override;

    void mousePressing(QMouseEvent*) override;

    void mouseMoving(QMouseEvent *) override;

    bool isInside(QMouseEvent*) override;
protected:

    void move() override;

    void calcArea() override;

    void calcPerimetr() override;

    void calcCentre() override;

    void decrease() override;

    void increase() override;
private:

    float rX, rY;
    float r;

    int polygonConst = 5;

};

#endif // CIRCLE_H


