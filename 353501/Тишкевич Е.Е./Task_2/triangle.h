#ifndef TRIANGLE_H
#define TRIANGLE_H

#include"shape.h"

class Triangle: public Shape
{
public:
    Triangle();
    float size=60;
    float s1=1.0;
    float s2=1.0;
    float s3=1.0;

    QPoint Fpoint=QPoint(-55, 20*sqrt(3));
    QPoint Spoint=QPoint(0, -35*sqrt(3));
    QPoint Tpoint=QPoint(55, 20*sqrt(3));
    float area() override;
    float perim() override;

    float getS1()override;
    void setS1(float)override;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // TRIANGLE_H
