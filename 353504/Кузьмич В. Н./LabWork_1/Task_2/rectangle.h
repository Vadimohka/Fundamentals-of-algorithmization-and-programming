#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figures.h"

class rectangle : public figures{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // RECTANGLE_H
