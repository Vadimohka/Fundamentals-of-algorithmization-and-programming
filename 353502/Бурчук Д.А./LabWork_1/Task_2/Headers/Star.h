#ifndef LAB1TASK2_STAR_H
#define LAB1TASK2_STAR_H

#include "Figure.h"

class Star : public Figure {
public:
    explicit Star(QWidget *parent);

    void draw(QPainter *painter) override;

    void drawMove(QMouseEvent *event) override;

private:
    void setStar(int thorns, int eventX, int eventY);

protected:
    int _xRadiusB;

    int _yRadiusB;

    int _radiusS;

    void findArea() override;

    void findPerimeter() override;
};


#endif //LAB1TASK2_STAR_H
