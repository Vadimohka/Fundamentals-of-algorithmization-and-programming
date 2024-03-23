#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figure.h"

class Triangle : public Figure
{
private:
    qreal side1;
    qreal side2;
    qreal side3;
public:
    Triangle();
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
    void setValueC(double value) override;
    void setValueA(double value) override;
    void setValueB(double value) override;
    void calculatePoints() override;
};

#endif // TRIANGLE_H
