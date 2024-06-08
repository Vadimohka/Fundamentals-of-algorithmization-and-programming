#ifndef STAR_H
#define STAR_H

#include "figure.h"
#include <QPainter>

class star : public figure
{
    Q_OBJECT
public:
    star();
    ~star();
    void initialization();
    int R,G,B,PenSize;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // STAR_H
