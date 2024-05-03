#ifndef LAB1TASK2_RECTANGLE_H
#define LAB1TASK2_RECTANGLE_H

#include "Figure.h"

class Rectangle : public Figure {
public:
    explicit Rectangle(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawMove(QMouseEvent *event) override;

private:
    int _xRadius;

    int _yRadius;

    void findArea() override;

    void findPerimeter() override;
};


#endif //LAB1TASK2_RECTANGLE_H
