#ifndef BACKGROUND_H
#define BACKGROUND_H
#include "plane.h"

class Background: public MovingRectangle, public QObject {
public:
    Background();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // BACKGROUND_H
