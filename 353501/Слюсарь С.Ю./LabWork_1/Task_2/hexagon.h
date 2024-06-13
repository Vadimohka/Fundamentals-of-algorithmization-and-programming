#ifndef HEXAGON_H
#define HEXAGON_H
#include "figure.h"

class Hexagon : public Figure
{
public:
    Hexagon(int x = -60, int y = 0, int width = 120, int height = 100);
    ~Hexagon();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    double area() override;
    double perimetr() override;
    QPointF centerOfMass() override;

private:
    int x1_;
    int y1_;
    int x2_;
    int y2_;
    int x3_;
    int y3_;
    int x4_;
    int y4_;
    int x5_;
    int y5_;
    int x6_;
    int y6_;
    int width_;
    int height_;

    // Figure interface
public slots:
    void move() override;
    void moveBack() override;
    void rotate() override;
    void rotateBack() override;
    void scale() override;
    void scaleBack() override;
};

#endif // HEXAGON_H
