#ifndef CIRCLE_H
#define CIRCLE_H

#include "figures.h"

class circle : public figures{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // CIRCLE_H
