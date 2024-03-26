#ifndef HEXAGON_H
#define HEXAGON_H

#include <QtWidgets>
#include "figures.h"

class figureHexagon : public figures {
public:
    figureHexagon() = default;
    void setPoints(QMouseEvent *) override;
};


#endif
