#ifndef LAB0T2_FIGURETRIANGLE_H
#define LAB0T2_FIGURETRIANGLE_H

#include <QtWidgets>
#include "figures.h"

class figureTriangle : public figures {
public:
    figureTriangle() = default;

    void setPoints(QMouseEvent *) override;

};


#endif //LAB0T2_FIGURETRIANGLE_H
