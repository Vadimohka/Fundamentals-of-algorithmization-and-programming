#ifndef LAB1TASK2_LINE_H
#define LAB1TASK2_LINE_H

#include "Figure.h"

class Line : public Figure {
public:
    explicit Line(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawPress(QMouseEvent *event) override;

    void drawMove(QMouseEvent *event) override;

    void pushPoint();

public
    slots:

            void increasingSize()
    override;

    void diminishingSize() override;

    void findArea() override;

    void findPerimeter() override;
};


#endif //LAB1TASK2_LINE_H
