#ifndef CAR_H
#define CAR_H

#include <QPropertyAnimation>
#include <QTransform>

#include "rectangle.h"

class Car : public Rectangle
{
    Q_PROPERTY(qreal doorRotation READ doorRotation WRITE setDoorRotation NOTIFY doorRotationChanged)

public:
    Car();
    Rectangle *rect;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    int lightsOn_ = 0;
    int openDoor_ = 0;
    int stop = 0;

public slots:
    void lightsOnOff();
    void openDoor();
    void move() override;
    void moveBack() override;
};

#endif // CAR_H
