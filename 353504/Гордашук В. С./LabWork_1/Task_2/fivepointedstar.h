#ifndef FIVEPOINTEDSTAR_H
#define FIVEPOINTEDSTAR_H

#include "star.h"

class FivePointedStar : public Star
{
public:
    FivePointedStar(int x = 0, int y = 0, int radius = 100);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    double area() override;
    double perimetr() override;
    QPointF centerOfMass() override;

public slots:
    void move() override;
    void moveBack() override;
    void rotate() override;
    void rotateBack() override;
    void scale() override;
    void scaleBack() override;
};

#endif // FIVEPOINTEDSTAR_H
