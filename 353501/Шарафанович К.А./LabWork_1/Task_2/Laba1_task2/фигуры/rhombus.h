#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <QtWidgets>
#include "figures.h"

class rhombus : public figures
{
public:
    rhombus() = default;

    void setPoints(QMouseEvent *) override;
};

#endif // RHOMBUS_H
