#ifndef HEXAGON_H
#define HEXAGON_H

#include <QtWidgets>
#include "figures.h"

class hexagon : public figures
{
public:
    hexagon() = default;

    void setPoints(QMouseEvent*) override;
};

#endif // HEXAGON_H
