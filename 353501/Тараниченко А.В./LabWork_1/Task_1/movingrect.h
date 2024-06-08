#ifndef MOVINGRECT_H
#define MOVINGRECT_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QPainter>
#include <QMainWindow>
#include <QTimer>
#include <QGraphicsScene>
#include <QPushButton>
#include <QGraphicsView>
#include <QDockWidget>
#include <QVBoxLayout>

class movingrect : public QGraphicsRectItem , public QObject{
public:
    movingrect();
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();
};

#endif // MOVINGRECT_H
