#ifndef TRUCK_H
#define TRUCK_H

#include "rectangle.h"

class truck : public rectangle{
public:
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;
};

#endif // TRUCK_H
