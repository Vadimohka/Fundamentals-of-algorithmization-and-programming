#ifndef POLYGON_H
#define POLYGON_H


#include "figure.h"
#include <QPainter>

class polygon : public figure
{
    Q_OBJECT
public:
    polygon();
    ~polygon();
    void initialization();
    int R,G,B,PenSize;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // POLYGON_H
