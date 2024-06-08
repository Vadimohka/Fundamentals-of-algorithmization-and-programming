#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "figure.h"
#include <QPainter>

class rectangle : public figure
{
    Q_OBJECT
public:
    rectangle();
    ~rectangle();
    void initialization();
    int R,G,B,PenSize;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // RECTANGLE_H
