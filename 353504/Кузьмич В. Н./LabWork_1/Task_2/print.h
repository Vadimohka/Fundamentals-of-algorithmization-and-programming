#ifndef PRINT_H
#define PRINT_H

#include "figures.h"

class print : public figures{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
};

#endif // PRINT_H
