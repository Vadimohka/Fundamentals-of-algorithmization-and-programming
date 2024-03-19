#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "figures.h"

class triangle : public figures{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // TRIANGLE_H
