#ifndef LAB1TASK2_HEXAGON_H
#define LAB1TASK2_HEXAGON_H

#include "Figure.h"

class Hexagon : public Figure {
public:
    explicit Hexagon(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawMove(QMouseEvent *event) override;

private:
    int _xRadius;

    int _yRadius;

    void findArea() override;

    void findPerimeter() override;
};


#endif //LAB1TASK2_HEXAGON_H
