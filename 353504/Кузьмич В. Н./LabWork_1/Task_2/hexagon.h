#ifndef HEXAGON_H
#define HEXAGON_H

#include "figures.h"

class hexagon : public figures
{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // HEXAGON_H
