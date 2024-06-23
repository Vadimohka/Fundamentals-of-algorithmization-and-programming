#ifndef WHEEL_H
#define WHEEL_H
#include "circle.h"
#include <QGraphicsScene>

class Wheel : public Circle
{
public:
    explicit Wheel(QGraphicsScene *parent = 0);
    ~Wheel();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // WHEEL_H
