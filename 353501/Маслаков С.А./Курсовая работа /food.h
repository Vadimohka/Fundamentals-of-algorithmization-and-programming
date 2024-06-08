#ifndef FOOD_H
#define FOOD_H
#include <QGraphicsScene>
#include <QPainter>
#include <QTimer>
#include <QGraphicsPixmapItem>
class Food : public QGraphicsPixmapItem
{

public:
    Food();
    Food(long double x,long double y);
};

#endif // FOOD_H
