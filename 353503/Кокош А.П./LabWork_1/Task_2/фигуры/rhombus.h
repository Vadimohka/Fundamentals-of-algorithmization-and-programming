#ifndef RHOMBUS_H
#define RHOMBUS_H

#include <QtWidgets>
#include "figures.h"

class rhombus : public figures
{
public:
    rhombus() = default;

    void setPoints(QMouseEvent * /*event*/) override;
};

#endif // RHOMBUS_H
