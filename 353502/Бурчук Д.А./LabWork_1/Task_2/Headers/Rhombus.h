#ifndef LAB1TASK2_RHOMBUS_H
#define LAB1TASK2_RHOMBUS_H

#include "Figure.h"

class Rhombus : public Figure {
public:
    explicit Rhombus(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawMove(QMouseEvent *event) override;

private:
    int _xRadius;

    int _yRadius;

    void findArea() override;

    void findPerimeter() override;
};


#endif //LAB1TASK2_RHOMBUS_H
