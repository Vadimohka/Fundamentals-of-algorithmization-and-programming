#ifndef FLAG_H
#define FLAG_H

#include "rectangle.h"

#include <QMainWindow>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsItem>

class Flag : public Rectangle
{
public:
    Flag();

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
};
#endif // FLAG_H
