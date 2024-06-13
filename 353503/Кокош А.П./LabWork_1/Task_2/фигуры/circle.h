#ifndef CIRCLE_H
#define CIRCLE_H

#include <QtWidgets>
#include "figures.h"

class circle : public figures
{
public:
    circle() = default;

    void draw(QPainter * /*unused*/) override;

    void move() override;

private:
    void findSquare() override;

    void findPerimetr() override;

    double radius;

    void moveCenter() override {}

    void clear() override
    {
        scale = 1;
        lastScale = 1;
        mouseWhenPress = {0, 0};
        mouseMoveWhenPress = {0, 0};
        mouseCurrentPos = {0, 0};
        mouseMoveCurrentPos = {0, 0};
        perimetr = 0;
        square = 0;
        center = {0, 0};
    }
};

#endif // CIRCLE_H
