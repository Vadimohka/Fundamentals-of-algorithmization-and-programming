#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H

#include <QGraphicsRectItem>
#include <QGraphicsView>
#include <QObject>
#include <QPainter>

class MovingRectangle : public QGraphicsRectItem, public QObject {
public:
    MovingRectangle();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};

#endif // MOVINGRECTANGLE_H
