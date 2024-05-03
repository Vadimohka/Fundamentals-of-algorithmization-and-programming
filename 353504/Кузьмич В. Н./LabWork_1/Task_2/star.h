#ifndef STAR_H
#define STAR_H

#include "figures.h"

class star : public figures{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // STAR_H
