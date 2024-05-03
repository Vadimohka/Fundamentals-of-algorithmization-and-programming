#ifndef LAB0T2_FIGURECIRCLE_H
#define LAB0T2_FIGURECIRCLE_H

#include <QtWidgets>
#include "figures.h"


class figureCircle : public figures {
public:
    figureCircle() = default;

    void draw(QPainter *) override;

    void move() override;

private:

    void findSquare() override;

    void findPerimeter() override;

    double r;

    void updateCenter() override {}

    void clear() override {
        scale = 1;
        lastScale = 1;
        mousePress = {0, 0};
        mouseMovePress = {0, 0};
        mouseNow = {0, 0};
        mouseMoveNow = {0, 0};
        perimeter = 0;
        square = 0;
        center = {0, 0};
    }


};


#endif
