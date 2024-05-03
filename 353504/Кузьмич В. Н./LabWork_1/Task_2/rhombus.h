#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "figures.h"

class rhombus : public figures{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // RHOMBUS_H
