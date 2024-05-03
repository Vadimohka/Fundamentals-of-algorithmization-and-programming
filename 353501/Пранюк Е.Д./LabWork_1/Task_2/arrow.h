#ifndef ARROW_H
#define ARROW_H

#include "figure.h"

class Arrow : public Figure
{
public:
    Arrow();

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    float perimeter();
};

#endif // ARROW_H
