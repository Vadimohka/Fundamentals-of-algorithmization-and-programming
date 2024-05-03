#ifndef SQUARE_H
#define SQUARE_H

#include "figure.h"

class Square : public Figure
{

public:
    explicit Square(QPointF point);

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
};

#endif // SQUARE_H
