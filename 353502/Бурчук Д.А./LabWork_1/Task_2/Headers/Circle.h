#ifndef LAB1TASK2_CIRCLE_H
#define LAB1TASK2_CIRCLE_H


#include "Figure.h"


class Circle : public Figure {
public:
    explicit Circle(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawMove(QMouseEvent *event) override;

    void diminishingSize() override;

    void increasingSize() override;

    void rotateRight() override;

    void rotateLeft() override;

private:
    long double _xRadius;

    long double _yRadius;

    void findArea() override;

    void findPerimeter() override;
};


#endif //LAB1TASK2_CIRCLE_H
