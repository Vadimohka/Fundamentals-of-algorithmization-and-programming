#ifndef RIGHTHANDMAN_H
#define RIGHTHANDMAN_H

#include "lefthandman.h"
class RightHandMan:public LeftHandMan
{
public:
    RightHandMan();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // RIGHTHANDMAN_H
