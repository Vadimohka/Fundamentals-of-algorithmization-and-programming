#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "figure.h"
#include <QPainter>

class ellipse : public figure
{
    Q_OBJECT
public:
    ellipse();
    ~ellipse();
    void initialization();
    int R,G,B,PenSize;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ELLIPSE_H
