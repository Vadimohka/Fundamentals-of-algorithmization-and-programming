#ifndef WHEEL_H
#define WHEEL_H

#include "circle.h"

class Wheel : public Circle{
public:
    bool press = 0;

    explicit Wheel(Circle *parent1 = nullptr);

    void paintEvent(QPaintEvent *event) override;
    void drawWheel(QPainter *painter);
    void keyPressEvent(QKeyEvent *event) override;
    void keyReleaseEvent(QKeyEvent *event) override;
    void rotate();

private:
    qreal angle = 0.0;
    bool isSquare = 0;
};

#endif // WHEEL_H
