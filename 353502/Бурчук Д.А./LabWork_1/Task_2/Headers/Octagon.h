#ifndef LAB1TASK2_OCTAGON_H
#define LAB1TASK2_OCTAGON_H

#include "Figure.h"

class Octagon : public Figure {
public:
    explicit Octagon(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawMove(QMouseEvent *event) override;

private:
    int _xRadius;

    int _yRadius;

    void findArea() override;

    void findPerimeter() override;
};

#endif //LAB1TASK2_OCTAGON_H
