#ifndef LAB0T2_FIGURESQUARE_H
#define LAB0T2_FIGURESQUARE_H

#include <QtWidgets>
#include "figures.h"


class figureSquare : public figures {
public:
    figureSquare() = default;

    void setPoints(QMouseEvent *me) override;

};


#endif
