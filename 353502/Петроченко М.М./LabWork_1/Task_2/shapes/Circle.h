//
// Created by acryoz on 18.2.24.
//

#ifndef UNTITLED_CIRCLE_H
#define UNTITLED_CIRCLE_H

#include "figure.h"

class Circle: public figure {
public:
    Circle();
    void move() override;
    void resize(int) override;
    void draw(QPainter*) override;
    double calculatePerimeter() override;
    double calculateArea() override;
    void rotate(int) override;
    QPointF findCentre() override;
    void addPoint(QPointF) override;
private:
    double radius;
};


#endif //UNTITLED_CIRCLE_H
