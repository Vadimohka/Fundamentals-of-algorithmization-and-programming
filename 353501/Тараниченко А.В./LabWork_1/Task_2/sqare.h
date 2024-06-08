#ifndef SQARE_H
#define SQARE_H

#include "figure.h"
#include <QPainter>

class Sqare : public figure
{
    Q_OBJECT
public:
    Sqare();
    ~Sqare();
    void initialization();
    int R,G,B,PenSize;
private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // SQARE_H
