#ifndef WHEEL_H
#define WHEEL_H

#include "circle.h"
#include <QTimer>
#include <cmath>

class wheel : public circle
{
private:
    int movingX, movingY;
    double angle;

public:
    wheel();
    void setPosition(int x, int y);

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
};

#endif // WHEEL_H
