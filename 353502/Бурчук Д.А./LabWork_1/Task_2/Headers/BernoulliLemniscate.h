#ifndef LAB1TASK2_BERNOULLILEMNISCATE_H
#define LAB1TASK2_BERNOULLILEMNISCATE_H

#include "Figure.h"

class BernoulliLemniscate : public Figure {
public:
    explicit BernoulliLemniscate(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawPress(QMouseEvent *event) override;

    void drawMove(QMouseEvent *event) override;

private:
    float _radiusC;

    void findArea() override;

    void findPerimeter() override;
};


#endif //LAB1TASK2_BERNOULLILEMNISCATE_H
