#ifndef SQUARE_H
#define SQUARE_H

#include <QtWidgets>
#include "figures.h"

class figureSquare : public figures {
public:
    figureSquare() = default;
    void setPoints(QMouseEvent *me) override;

};

#endif
