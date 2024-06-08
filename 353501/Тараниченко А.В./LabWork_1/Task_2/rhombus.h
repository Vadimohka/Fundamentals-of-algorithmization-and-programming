#ifndef RHOMBUS_H
#define RHOMBUS_H
#include "figure.h"
#include <QPainter>

class rhombus: public figure
{
    Q_OBJECT
public:
    rhombus();
    ~rhombus();
    void initialization();
    int R,G,B,PenSize;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};


#endif // RHOMBUS_H
