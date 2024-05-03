#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <QtWidgets>
#include "figures.h"

class figureRhombus : public figures {
public:
    figureRhombus() = default;
    void setPoints(QMouseEvent *me) override;

};

#endif
