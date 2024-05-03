#ifndef ROCKET_H
#define ROCKET_H

#include "Fire.h"

class Rocket : public MovingLine
{
    Q_OBJECT
public:
    explicit Rocket(QWidget *parent);

    void paintEvent(QPaintEvent *event) override;
};

#endif // ROCKET_H
