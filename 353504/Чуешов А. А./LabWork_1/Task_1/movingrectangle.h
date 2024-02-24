#ifndef MOVINGRECTANGLE_H
#define MOVINGRECTANGLE_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QApplication>
#include <QMainWindow>
#include <QDockWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QPushButton>
#include <QVBoxLayout>
#include <QGraphicsEllipseItem>

class MovingRectangle : public QGraphicsRectItem, public QObject
{
public:
    MovingRectangle();
    void moveLeft();
    void moveRight();
};

#endif // MOVINGRECTANGLE_H
