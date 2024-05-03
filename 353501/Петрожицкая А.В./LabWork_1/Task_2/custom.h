#ifndef CUSTOM_H
#define CUSTOM_H

#include <QObject>
#include <QGraphicsItem>
#include "figure.h"

class Custom : public Figure
{

public:

    Custom();
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // CUSTOM_H
