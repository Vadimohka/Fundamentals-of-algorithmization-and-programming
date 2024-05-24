#ifndef LAB1TASK2_TRIANGLE_H
#define LAB1TASK2_TRIANGLE_H

#include "Figure.h"

class Triangle : public Figure {
public:
    explicit Triangle(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawPress(QMouseEvent *event) override;

    void drawMove(QMouseEvent *event) override;

private:
    void findArea() override;

    void findPerimeter() override;
};


#endif //LAB1TASK2_TRIANGLE_H
