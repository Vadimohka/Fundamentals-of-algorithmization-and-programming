#ifndef ARROW_H
#define ARROW_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Arrow : public Figure
{
public:
    Arrow();

private:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};

#endif // ARROW_H
