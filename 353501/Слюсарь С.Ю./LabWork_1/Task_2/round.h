#ifndef ROUND_H
#define ROUND_H

#include "figure.h"

class Round : public Figure
{
public:
    Round(int x = -30, int y = -30, int xradius = 120, int yradius = -1);
    ~Round();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    double area() override;
    double perimetr() override;
    QPointF centerOfMass() override;

private:
    int x_;
    int y_;
    int xradius_;
    int yradius_;

    // Figure interface
public slots:
    void move() override;
    void moveBack() override;
    void rotate() override;
    void rotateBack() override;
    void scale() override;
    void scaleBack() override;
};

#endif // ROUND_H
