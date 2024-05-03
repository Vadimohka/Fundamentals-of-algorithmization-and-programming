#ifndef ROAD_H
#define ROAD_H

#include <QObject>
#include <QPainter>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

class Road : public QGraphicsRectItem
{
public:
    Road();
    virtual void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
};

#endif // ROAD_H
