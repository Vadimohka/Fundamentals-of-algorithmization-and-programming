#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figures.h"
class Rhombus: public figure
{
public:
    void setP(QMouseEvent *)override;

};

#endif // RHOMBUS_H
