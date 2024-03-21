#ifndef HEXAGON_H
#define HEXAGON_H
#include "figures.h"

class Hexagon: public figure
{
public:
    void setP(QMouseEvent *)override;
    Hexagon() = default;
};

#endif // HEXAGON_H
