#ifndef LAB1TASK2_SQUARE_H
#define LAB1TASK2_SQUARE_H


#include "Figure.h"


class Square : public Figure {
public:

    explicit Square(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawMove(QMouseEvent *event) override;

private:
    int _xRadius;

    int _yRadius;

    void findArea() override;

    void findPerimeter() override;
};


#endif //LAB1TASK2_SQUARE_H
