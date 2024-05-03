#ifndef DOOR_H
#define DOOR_H

#include "MovingRectangle.h"

class Door : public MovingRectangle
{
public:
    Door(QWidget *parent = nullptr);
    bool isOpen;
    void toggle();
protected:
    void paintEvent(QPaintEvent *) override;
};

#endif // DOOR_H
