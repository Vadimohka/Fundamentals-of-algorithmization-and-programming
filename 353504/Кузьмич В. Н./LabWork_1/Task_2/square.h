#ifndef SQUARE_H
#define SQUARE_H

#include "figures.h"

class square : public figures{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // SQUARE_H
