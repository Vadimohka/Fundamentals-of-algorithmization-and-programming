#ifndef ROCKET_H
#define ROCKET_H
#include "segment.h"

class Rocket : public Segment
{
private:
    int color = 0;
public:
    Rocket(int color);
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // ROCKET_H
