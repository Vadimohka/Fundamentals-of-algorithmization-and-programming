#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <QtWidgets>
#include "figures.h"

class figureTriangle : public figures {
public:
    figureTriangle() = default;
    void setPoints(QMouseEvent *) override;

};


#endif
