#ifndef TRIANGLEE_H
#define TRIANGLEE_H

#include "figure.h"
#include <QPainter>

class trianglee : public figure
{
    Q_OBJECT
public:
    trianglee();
    ~trianglee();
    void initialization();
    int R,G,B,PenSize;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // TRIANGLEE_H
