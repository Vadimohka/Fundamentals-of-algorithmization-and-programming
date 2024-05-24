#ifndef LAB0T2_FIGUREHEXAGON_H
#define LAB0T2_FIGUREHEXAGON_H

#include <QtWidgets>
#include "figures.h"

class figureHexagon : public figures {
public:
    figureHexagon() = default;

    void setPoints(QMouseEvent *) override;
};


#endif //LAB0T2_FIGUREHEXAGON_H
