#ifndef TOWER_H
#define TOWER_H

#include "ring.h"
#include <QGraphicsItem>
#include <QPainter>
#include <QStack>
#include <QGraphicsScene>

class Tower : public QGraphicsItem
{
public:
    Tower();

    QRectF boundingRect() const override;
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget) override;

    void createRing(Ring* newRing);
    void addRing(Ring* newRing);
    void popRing();

    void clear();
    Ring *top();

private:
    QStack<Ring*> stackRings;
};

#endif // TOWER_H
