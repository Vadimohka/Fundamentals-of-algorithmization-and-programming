#ifndef ROCKET_H
#define ROCKET_H

#include "moveline.h"

class Rocket : public MoveLine
{
    Q_OBJECT
    QGraphicsLineItem *line1 = nullptr;
    QGraphicsLineItem *line2 = nullptr;
    QGraphicsLineItem *line3 = nullptr;
    QGraphicsLineItem *line4 = nullptr;
    QGraphicsLineItem *line5 = nullptr;
    QGraphicsLineItem *line6 = nullptr;
    QGraphicsLineItem *line7 = nullptr;
    QGraphicsLineItem *line8 = nullptr;
    QGraphicsLineItem *line9 = nullptr;
    QGraphicsLineItem *line10 = nullptr;
    QGraphicsLineItem *line11 = nullptr;
    QGraphicsLineItem *line12 = nullptr;
    QGraphicsLineItem *line13 = nullptr;
    QGraphicsEllipseItem *window = nullptr;
    QGraphicsLineItem *fireline1 = nullptr;
    QGraphicsLineItem *fireline2 = nullptr;
    QGraphicsLineItem *fireline3 = nullptr;
    QGraphicsLineItem *fireline4 = nullptr;
    QGraphicsLineItem *fireline5 = nullptr;
    QGraphicsLineItem *fireline6 = nullptr;

public:
    Rocket();
    ~Rocket();
    void Start();
    void Restart();
};

#endif // ROCKET_H
