#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "square.h"

class Rhombus : public BasicShape
{
public:
    Rhombus();
    float area() override;
    float perimeter() override;
    void setLength(int value) override;
    void setWidth(int value) override;
    float getLength() override;
    float getWidth() override;
private:
    int length = 50;
    int width = 100;
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *) override;
};

#endif // RHOMBUS_H
