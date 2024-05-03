#ifndef PLANE_H
#define PLANE_H

#include "movingrect.h"

class Plane : public movingRect
{
    bool shassi = false;
public:
    Plane();
    ~Plane();
    void setShassi();
    void removeShassi();
protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // PLANE_H
