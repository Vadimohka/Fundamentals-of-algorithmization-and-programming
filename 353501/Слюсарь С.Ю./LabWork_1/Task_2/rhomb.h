#ifndef RHOMB_H
#define RHOMB_H

#include "figure.h"

class Rhomb : public Figure
{
public:
    Rhomb(int x = 0, int y1 = 0, int width = 120, int height = 120);
    ~Rhomb();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    double area() override;
    double perimetr() override;
    QPointF centerOfMass() override;

private:
    int x_;
    int y_;
    int height_;
    int width_;

public slots:
    void move() override;
    void moveBack() override;
    void rotate() override;
    void rotateBack() override;
    void scale() override;
    void scaleBack() override;
};

#endif // RHOMB_H
